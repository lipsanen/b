#pragma once

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <system_error>
#include "bdemo/bdemo.h"

namespace bdemo
{
    class ireader_t
    {
    public:
        virtual ~ireader_t() {}

        template<typename T>
        void read(T* dest)
        {
            read(dest, sizeof(T));
        }

        template<typename T>
        T read_value() { T out; read(&out); return out; }
        virtual uint32_t read(void* dest, uint32_t bytes) = 0;
        virtual bool eof() = 0;
        bool m_bEOF = false;
    };

    class filereader_t : public ireader_t
    {
    public:
        bool try_open(const char* filepath);
        void close();
        FILE* m_pFile = nullptr;
        virtual uint32_t read(void* dest, uint32_t bytes) override;
        virtual bool eof() override;
    };

    struct parser_t
    {
        static bdemo::error_code parse(ireader_t* reader, demo_t* output);
        void parse_header();
        bdemo::error_code parse_anymessage();
        bdemo::error_code parse_consolecmd();
        bdemo::error_code parse_datatables();
        bdemo::error_code parse_packet(messagetype_t type);
        bdemo::error_code parse_stop();
        bdemo::error_code parse_synctick();
        bdemo::error_code parse_usercmd();
        bdemo::error_code parse_stringtables();
        bdemo::error_code parse_customdata();

        ireader_t* m_pReader = nullptr;
        demo_t* m_pOutput = nullptr;
    };
}
