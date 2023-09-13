#pragma once

namespace bob
{
    inline void AssertMsg(const char* msg, ...) {}
    inline void ConMsg(const char* msg, ...) {}
    inline void Msg(const char* msg, ...) {}
    inline void Warning(const char* msg, ...) {}
    inline void DevMsg(const char* msg, ...) {}
    inline void DevWarning(const char* msg, ...) {}
    inline void VerifyEquals(...) { }
}