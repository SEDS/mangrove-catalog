// ACE ace/String_Base.h
// Structure: conditional-invariant

#ifndef ACE_STRING_BASE_H
#define ACE_STRING_BASE_H

#include <string.h>
#include <cstdlib>


template <class ACE_CHAR_T>
class ACE_String_Base
{
public:
   /**
    * Constructor that copies @a len CHARs of @a s into dynamically
    * allocated memory (will zero terminate the result).
    *
    * if release == true then a new buffer is allocated internally.
    *   s is copied to the internal buffer.
    * if release == false then the s buffer is used directly. If s == 0
    *   then it will _not_ be used, and instead the internal buffer
    *   is set to NULL_String_.
    *
    * @param s Non-zero terminated input string
    * @param len Length of non-zero terminated input string
    * @param the_allocator ACE_Allocator associated with string
    * @param release Allocator responsible(true)/not responsible(false) for
    *    freeing memory.
    * @return ACE_String_Base containing const ACE_CHAR_T *s
    */
    ACE_String_Base(const ACE_CHAR_T *s, size_t len, bool release = true);


   /**
    *  Copy @a len bytes of @a s (will zero terminate the result).
    *
    * If release == true then a new buffer is allocated internally if the
    *   existing one is not big enough to hold s. If the existing
    *   buffer is big enough, then it will be used. This means that
    *   set(*, *, 1) is illegal when the string is constructed with a
    *   non-owned const char*. (e.g. ACE_String_Base("test", 0, 0))
    *
    * If release == false then the s buffer is used directly, and any
    *   existing buffer is destroyed. If s == 0 then it will _not_ be
    *   used, and instead the internal buffer is set to NULL_String_.
    *
    *  @param s Non-zero terminated input string
    *  @param len Length of input string 's'
    *  @param release Allocator responsible(true)/not responsible(false) for
    *    freeing memory.
    */
    void set(const ACE_CHAR_T * s, size_t len, bool release);


protected:
   /**
    *  Length of the ACE_String_Base data buffer.  Keeping track of the
    *  length allows to avoid unnecessary dynamic allocations.
    */
    size_t buf_len_;

   /**
    *  Pointer to data.
    */
    ACE_CHAR_T *rep_;
};

#include "String_Base.cpp"

#endif /* ACE_STRING_BASE_H */