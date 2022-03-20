#pragma once



namespace rilib::collections
{

	template<typename array>
	class array_iterator
	{
	public:
		using val_t = typename array::val_t;
		using ptr_t = val_t*;
		using ref_t = val_t&;

	public:
		array_iterator(ptr_t ptr) : m_ptr(ptr) {}


		array_iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		array_iterator operator++(int)
		{
			array_iterator iterator = *this;
			++(*this);
			return iterator;
		}

		array_iterator& operator--()
		{
			m_ptr--;
			return *this;
		}

		array_iterator operator--(int)
		{
			array_iterator iterator = *this;
			--(*this);
			return iterator;
		}

		ref_t operator[](size_t index)
		{
			return *(m_ptr + index);
		}

		ptr_t operator->()
		{
			return m_ptr;
		}

		ref_t operator*()
		{
			return *m_ptr;
		}

		bool operator==(const array_iterator& other) const
		{
			return m_ptr == other.m_ptr;
		}

		bool operator!=(const array_iterator& other) const
		{
			return m_ptr != other.m_ptr;
		}

	private:
		ptr_t m_ptr;
	};


	template<typename T, const size_t m_size>
	class array
	{
	public:
		using val_t = T;
		using iterator = array_iterator<array<T, m_size>>;

	public:

		array() {}

		array(const T& initial_value)
		{
			std::fill(begin(), end(), initial_value);
		}

		array(const T* data)
		{
			memcpy(m_data, data, m_size * sizeof(T));
		}

		array(const T(&init)[m_size])
		{
			memcpy(m_data, init, m_size * sizeof(T));
		}

		array(T* data)
		{
			m_data = data;
		}

		const T& operator[](size_t index) const { return m_data[index]; }

		T& operator[](size_t index) { return m_data[index]; }

		T* data() { return m_data; }
		[[nodiscard]] const T* data() const { return m_data; }

		[[nodiscard]] constexpr size_t size() const { return m_size; }

		iterator begin()
		{
			return array_iterator<array<T, m_size>>(m_data);
		}

		iterator end()
		{
			return array_iterator<array<T, m_size>>(m_data + m_size);
		}




	private:
		T m_data[m_size];
	};


}