#pragma once

namespace rilib::collections
{

	template<typename array>
	class array_iterator
	{
	public:
		using val_t = typename array::T;
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


	template<typename T, size_t m_size>
	class array
	{
	public:
		using iterator = array_iterator<array<T, m_size>>;

	public:
		const T& operator[](size_t index) const { return m_data[index]; }

		T& operator[](size_t index) { return m_data[index]; }

		T* data() { return m_data; }
		const T* data() const { return m_data; }

		[[nodiscard("Pure function")]] constexpr size_t size() const { return m_size; }

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