// ACE ace/String_Base.cpp
// Structure: conditional-invariant

#ifndef ACE_STRING_BASE_CPP
#define ACE_STRING_BASE_CPP

// Constructor
template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base(const ACE_CHAR_T *s, size_t len, bool release)
    : buf_len_(0),
      // Static Code Analysis Tool event: 'rep_' is set to NULL. Dereferenced later, causing the null pointer dereference.
      rep_(0)
{
    this->set(s, len, release);
}

// set() method
template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::set(const ACE_CHAR_T *s, size_t len, bool release)
{
    if (s != 0 && len != 0 && release && this->buf_len_ < len + 1)
    {
        // Assuming that the 'else if' clause below is executed (as Static Code Analysis Tool believes),
        // this 'if' clause would have had to have been executed, causing the clause below
        // NOT to be executed. This is a contradition, so therefore the warning is a FP.

        // Also, it is believed to be an invariant in the original program that whenever
        // buf_len_ > 0, rep_ != null. Note that if the 'else if' clause below executes,
        // buf_len_ must be greater than 0.
        ;
    }
    else if (s != 0 && len != 0 && release)
    {
        // Static Code Analysis Tool FP: Null Pointer Dereference. The body of memcpy() dereferences 'rep_', but it is NULL.
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        memcpy(this->rep_, s, len * sizeof(ACE_CHAR_T));
        this->rep_[len] = 0;
    }
}

#endif  /* ACE_STRING_BASE_CPP */
