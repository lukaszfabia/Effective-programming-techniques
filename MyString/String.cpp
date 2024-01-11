#include "String.h"

using namespace utils;

/**
 * @class String
 * @brief An implementation of a String class and utilities methods.
 */

/**
 * @brief Default constructor for the String class.
 */
String::String() : data_(nullptr) {}

/**
 * @brief Constructor for the String class that takes a C-style string as input.
 * @param data The C-style string to initialize the String object with.
 */
String::String(const char *data)
{
    this->data_ = new char[len(data) + 1];
    this->data_ = copy(data);
}

/**
 * @brief Copy constructor for the String class.
 * @param string The String object to be copied.
 */
String::String(const String &string)
{
    this->data_ = new char[len(string.data_) + 1];
    this->data_ = copy(string.data_);
}

/**
 * @brief Move constructor for object String.
 * @param string The string to be moved.
 */
String::String(String &&string) noexcept
{
    this->data_ = new char[len(string.data_) + 1];
    this->data_ = copy(string.data_);
    string.data_ = nullptr;
}

/**
 * @brief Move constructor for character array.
 * @param string The character array to be moved.
 */
String::String(char *&&string) noexcept
{
    this->data_ = new char[len(string) + 1];
    this->data_ = copy(string);
    string = nullptr;
}

/**
 * @brief Destructor for the String class.
 */
String::~String()
{
    delete[] data_;
}

/**
 * @brief Returns a C-style string representation of the String object.
 * @return A C-style string representation of the String object.
 */
const char *String::toString() const
{
    return data_;
}

/**
 * @brief Assignment operator overload for the String class.
 * @param string The String object to be assigned.
 * @return A reference to the assigned String object.
 */
String &String::operator=(const String &string)
{
    if (this != &string)
    {
        delete[] data_;
        data_ = new char[len(string.data_) + 1];
        data_ = copy(string.data_);
    }
    return *this;
}

/**
 * @brief Assignment operator overload for the String class that takes a C-style string as input.
 * @param string The C-style string to be assigned.
 * @return A reference to the assigned String object.
 */
String &String::operator=(const char *string)
{
    delete[] data_;
    data_ = copy(string);
    return *this;
}

/**
 * @brief Move assignment operator overload for assigning a string to another string.
 * @param string The string to be assigned.
 * @return A reference to the assigned string.
 */
String &String::operator=(String &&string) noexcept
{
    if (this != &string)
    {
        delete data_;
        data_ = new char[len(string.data_) + 1];
        data_ = copy(string.data_);
        string.data_ = nullptr;
    }
    return *this;
}

/**
 * @brief Move assignment operator overload for assigning a character array to the string.
 * @param string The character array to be assigned.
 * @return A reference to the assigned string.
 */
String &String::operator=(char *&&string) noexcept
{
    if (data_ != *&string)
    {
        delete[] data_;
        data_ = new char[len(string) + 1];
        data_ = copy(string);
        string = nullptr;
    }
    return *this;
}

/**
 * @brief Addition operator overload for the String class.
 * @param string The String object to be concatenated.
 * @return A new String object that is the concatenation of the two String objects.
 */
String String::operator+(const String &string)
{
    size_t new_len = len(string.data_) + len(data_) + 1;
    char *res = new char[new_len];
    res = copy(data_);

    char *rhs = copy(string.data_);

    for (size_t i = len(data_); i < new_len - 1; i++) // Fixed the loop condition
    {
        res[i] = rhs[i - len(data_)]; // Fixed the index calculation
    }
    res[new_len - 1] = '\0';

    delete[] rhs;
    String result(res);
    delete[] res;
    return result;
}

/**
 * @brief Addition operator overload for the String class that takes a C-style string as input.
 * @param string The C-style string to be concatenated.
 * @return A new String object that is the concatenation of the String object and the C-style string.
 */
String String::operator+(const char *string)
{
    size_t new_len = len(string) + len(data_) + 1;
    char *res = new char[new_len];
    res = copy(data_);

    char *rhs = copy(string);

    for (size_t i = len(data_); i < new_len - 1; i++) // Fixed the loop condition
    {
        res[i] = rhs[i - len(data_)]; // Fixed the index calculation
    }
    res[new_len - 1] = '\0';

    delete[] rhs;
    String result(res);
    delete[] res;
    return result;
}

/**
 * @brief Compound assignment operator overload for the String class.
 * @param string The String object to be concatenated.
 * @return A reference to the modified String object.
 */
String &String::operator+=(const String &string)
{
    *this = *this + string;
    return *this;
}

/**
 * @brief Compound assignment operator overload for the String class that takes a C-style string as input.
 * @param string The C-style string to be concatenated.
 * @return A reference to the modified String object.
 */
String &String::operator+=(const char *string)
{
    size_t new_len = len(data_) + len(string) + 1;
    char *res = new char[new_len];
    res = copy(data_);
    char *rhs = copy(string);

    for (size_t i = len(data_); i < new_len - 1; i++)
    {
        res[i] = rhs[i - len(data_)];
    }
    res[new_len - 1] = '\0';

    delete[] data_;
    data_ = new char[len(res) + 1];
    data_ = copy(res);
    delete[] res;
    delete[] rhs;
    return *this;
}

/**
 * @brief Conversion operator overload for the String class.
 * @return true if the String object is empty (nullptr), false otherwise.
 */
String::operator bool() const
{
    return data_ == nullptr;
}

/**
 * @brief Returns a substring of the String object.
 * @param begin_index The starting index of the substring.
 * @param last_index The ending index of the substring.
 * @return A C-style string representing the substring.
 */
const char *String::substring(size_t begin_index, size_t last_index)
{
    if (is_correct_index(begin_index, last_index))
    {
        char *tmp = new char[last_index - begin_index + 2];
        size_t index = 0;
        for (size_t offset = begin_index; offset <= last_index; ++offset)
        {
            tmp[index] = data_[offset];
            ++index;
        }
        tmp[index] = '\0';
        const char *result = new char[index + 1];
        result = copy(tmp);
        delete []tmp;
        return result;
    }
    else
    {
        return "\0";
    }
}

/**
 * @brief Returns a substring of the String object starting from the specified index.
 * @param begin_index The starting index of the substring.
 * @return A C-style string representing the substring.
 */
const char *String::substring(size_t begin_index)
{
    return substring(begin_index, len(data_));
}

/**
 * @brief Returns the character at the specified index.
 * @param index The index of the character.
 * @return The character at the specified index, or '\0' if the index is out of range.
 */
char String::char_at(size_t index)
{
    if (index < len(data_))
    {
        return data_[index];
    }
    else
    {
        return '\0';
    }
}

/**
 * @brief Checks if the given indices are valid for substring operations.
 * @param lhs The left index.
 * @param rhs The right index.
 * @return true if the indices are valid, false otherwise.
 */
bool String::is_correct_index(size_t lhs, size_t rhs)
{
    size_t length = len(data_);
    return rhs >= 0 && lhs < rhs && lhs < length && rhs <= length;
}

/**
 * @brief Calculates the length of a C-style string.
 * @param array The C-style string.
 * @return The length of the C-style string.
 */
inline size_t len(const char *array)
{
    size_t length = 0;
    while (array[length] != '\0')
    {
        length++;
    }
    return length;
}

/**
 * @brief Copies a C-style string.
 * @param array The C-style string to be copied.
 * @return A new copy of the C-style string.
 */
char *utils::copy(const char *array)
{
    size_t length = len(array);
    char *copy = new char[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        copy[i] = array[i];
    }
    copy[length] = '\0';
    return copy;
}

/**
 * @brief Calculates the length of a C-style string.
 * @param array The C-style string.
 * @return The length of the C-style string.
 */
size_t utils::len(const char *array)
{
    size_t index = 0;
    while (array[index] != '\0')
    {
        index++;
    }

    return index;
}