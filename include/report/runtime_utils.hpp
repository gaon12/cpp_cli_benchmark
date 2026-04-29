#pragma once

#include <string>

bool download_file_or_exit(const wchar_t* url, const wchar_t* destination, const char* label);
int read_menu_choice();
std::string json_escape(const std::string& input);
void write_result_json(
    long long plus_time_ms,
    long long pi_time_ms,
    long long download_time_ms,
    long long upscale_time_ms,
    long long compress_time_ms,
    long long surd_e_time_ms,
    long long decrypt_zip_time_ms,
    const std::string& cpu_name,
    unsigned long ram_size_gb,
    const std::string& gpu_name,
    int year,
    int month,
    int day,
    int hour,
    int minute,
    int wday,
    int windows_bits);
