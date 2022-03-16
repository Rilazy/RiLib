#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

//TRACE
//DEBUG
//INFO
//WARN
//ERROR
//CRITICAL
//OFF




namespace rilib::rilog
{
	/**
	 * \brief Flags used to initialize a Logger. Can be combined using or | operator.
	 */
	enum class LoggerFlags
	{
		IsAsync = 1,
		ToFile = (1 << 1),
		ToConsole = (1 << 2)
	};

	/**
	 * \brief Log level used to configure a Logger. Ascending order is Trace, Debug, Info, Warn, Error, Critical, Off. 
	 */
	enum class LoggerLevel
	{
		Trace = 0,
		Debug = 1,
		Info = 2,
		Warn = 3,
		Error = 4,
		Critical = 5,
		Off = 10,
	};

	constexpr LoggerFlags DEFAULT_LOGGER_FLAGS = LoggerFlags::ToConsole;
	constexpr LoggerLevel DEFAULT_LOGGER_LEVEL = LoggerLevel::Info;

	/**
	 * \brief Logger class used to create and manage loggers.
	 */
	class Logger
	{
	public:
		/**
		 * \brief Constructs a new Logger instance
		 * \param name The name of the underlying logger. Depending on pattern, this may be printed in the logged messages, Must be unique to each logger instance; otherwise runtime errors may occur which cannot be caught at compile time.
		 * \param filename The name of the file to log to. If the ToFile flag is not set, this parameter will be ignored. If to ToFile flag is set this parameter must not be nullptr.
		 * \param pattern The pattern string used to format the log messages, in spdlog format.
		 * \param flags LoggerFlags enum used to configure the logger. 
		 * \param level LoggerLevel enum used to configure the lowest error level that will be logged.
		 */
		Logger(const char* name, const char* filename, const char* pattern, LoggerFlags flags = DEFAULT_LOGGER_FLAGS, LoggerLevel level = DEFAULT_LOGGER_LEVEL);

		~Logger();

		
		void Trace(const char* message, ...);
		void Debug(const char* message, ...);
		void Info(const char* message, ...);
		void Warn(const char* message, ...);
		void Error(const char* message, ...);
		void Critical(const char* message, ...);

		void SetLevel(LoggerLevel level);

	private:
		const char* m_name, m_filename, m_pattern;
		std::shared_ptr<spdlog::logger> m_console;






	};
}