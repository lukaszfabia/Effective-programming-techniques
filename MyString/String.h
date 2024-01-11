#pragma once
#include <cstddef>

namespace utils
{
    /**
     * @brief A class representing a string.
     */
    class String
    {
    private:
        const char *data_; // Pointer to the character array representing the string

        /**
         * @brief Checks if the given indices are valid.
         * @param lhs The left-hand side index.
         * @param rhs The right-hand side index.
         * @return true if the indices are valid, false otherwise.
         */
        bool is_corret_index(size_t lhs, size_t rhs);

    public:
        /**
         * @brief Default constructor.
         */
        String();

        /**
         * @brief Constructor that initializes the string with the given character array.
         * @param data The character array to initialize the string with.
         */
        String(const char *data);

        /**
         * @brief Copy constructor.
         * @param string The string to be copied.
         */
        String(const String &string);

        /**
         * @brief Move constructor for object String.
         * @param string The string to be moved.
         */
        String(String &&string) noexcept;

        /**
         * @brief Move constructor for character array.
         * @param string The character array to be moved.
         */
        String(char *&&string) noexcept;

        /**
         * @brief Destructor.
         */
        ~String();

        /**
         * @brief Returns a pointer to the character array representing the string.
         * @return A pointer to the character array.
         */
        const char *toString() const;

        /**
         * @brief Assignment operator overload for assigning a string to another string.
         * @param string The string to be assigned.
         * @return A reference to the assigned string.
         */
        String &operator=(const String &string);

        /**
         * @brief Assignment operator overload for assigning a character array to the string.
         * @param string The character array to be assigned.
         * @return A reference to the assigned string.
         */
        String &operator=(const char *string);

        /**
         * @brief Move assignment operator overload for assigning a string to another string.
         * @param string The string to be assigned.
         * @return A reference to the assigned string.
         */
        String &operator=(String &&string) noexcept;

        /**
         * @brief Move assignment operator overload for assigning a character array to the string.
         * @param string The character array to be assigned.
         * @return A reference to the assigned string.
         */
        String &operator=(char *&&string) noexcept;

        /**
         * @brief Addition operator overload for concatenating two strings.
         * @param string The string to be concatenated.
         * @return The concatenated string.
         */
        String operator+(const String &string);

        /**
         * @brief Addition operator overload for concatenating a character array to the string.
         * @param string The character array to be concatenated.
         * @return The concatenated string.
         */
        String operator+(const char *string);

        /**
         * @brief Compound assignment operator overload for concatenating a string to the current string.
         * @param string The string to be concatenated.
         * @return A reference to the current string after concatenation.
         */
        String &operator+=(const String &string);

        /**
         * @brief Compound assignment operator overload for concatenating a character array to the current string.
         * @param string The character array to be concatenated.
         * @return A reference to the current string after concatenation.
         */
        String &operator+=(const char *string);

        /**
         * @brief Conversion operator to bool.
         * @return true if the string is not empty, false otherwise.
         */
        operator bool() const;

        /**
         * @brief Returns a substring of the string from the specified begin index to the specified last index.
         * @param begin_index The index of the first character of the substring.
         * @param last_index The index of the last character of the substring.
         * @return A pointer to the substring.
         */
        const char *substring(size_t begin_index, size_t last_index);

        /**
         * @brief Returns a substring of the string from the specified begin index to the end of the string.
         * @param begin_index The index of the first character of the substring.
         * @return A pointer to the substring.
         */
        const char *substring(size_t begin_index);

        /**
         * @brief Returns the character at the specified index.
         * @param index The index of the character.
         * @return The character at the specified index.
         */
        char char_at(size_t index);
    };

    /**
     * @brief Copies a character array.
     * @param array The character array to be copied.
     * @return A pointer to the copied character array.
     */
    char *copy(const char *array);

    /**
     * @brief Returns the length of a character array.
     * @param array The character array.
     * @return The length of the character array.
     */
    size_t len(const char *array);
}