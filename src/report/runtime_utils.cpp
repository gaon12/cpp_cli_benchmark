#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "report/runtime_utils.hpp"

using namespace std;

bool download_file_or_exit(const wchar_t* url, const wchar_t* destination, const char* label)
{
    const HRESULT hr = URLDownloadToFileW(NULL, url, destination, 0, NULL);
    if (SUCCEEDED(hr))
    {
        return true;
    }

    cerr << "\n[ERROR] 다운로드 실패: " << label << " (HRESULT: 0x" << hex << hr << dec << ")\n";
    cout << "10초 후 프로그램을 종료합니다.\n";
    Sleep(10000);
    exit(1);
}

int read_menu_choice()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        return -1;
    }
    return value;
}

string json_escape(const string& input)
{
    string output;
    output.reserve(input.size() + 16);
    for (char c : input)
    {
        switch (c)
        {
        case '\\': output += "\\\\"; break;
        case '\"': output += "\\\""; break;
        case '\n': output += "\\n"; break;
        case '\r': output += "\\r"; break;
        case '\t': output += "\\t"; break;
        default: output += c; break;
        }
    }
    return output;
}

void write_result_json(
    long long plus_time_ms,
    long long pi_time_ms,
    long long download_time_ms,
    long long upscale_time_ms,
    long long compress_time_ms,
    long long surd_e_time_ms,
    long long decrypt_zip_time_ms,
    const string& cpu_name,
    unsigned long ram_size_gb,
    const string& gpu_name,
    int year,
    int month,
    int day,
    int hour,
    int minute,
    int wday,
    int windows_bits)
{
    ofstream out("result.json", ios::trunc);
    if (!out.is_open())
    {
        cerr << "\n[ERROR] result.json 파일 생성에 실패했습니다.\n";
        return;
    }

    out << "{\n";
    out << "  \"version\": \"1.0.2\",\n";
    out << "  \"times_ms\": {\n";
    out << "    \"plus\": " << plus_time_ms << ",\n";
    out << "    \"pi\": " << pi_time_ms << ",\n";
    out << "    \"download\": " << download_time_ms << ",\n";
    out << "    \"upscale\": " << upscale_time_ms << ",\n";
    out << "    \"compress\": " << compress_time_ms << ",\n";
    out << "    \"surd_e\": " << surd_e_time_ms << ",\n";
    out << "    \"decrypt_zip\": " << decrypt_zip_time_ms << "\n";
    out << "  },\n";
    out << "  \"system\": {\n";
    out << "    \"cpu_name\": \"" << json_escape(cpu_name) << "\",\n";
    out << "    \"ram_size_gb\": " << ram_size_gb << ",\n";
    out << "    \"gpu_name\": \"" << json_escape(gpu_name) << "\",\n";
    out << "    \"windows_bits\": " << windows_bits << "\n";
    out << "  },\n";
    out << "  \"measured_at\": {\n";
    out << "    \"year\": " << year << ",\n";
    out << "    \"month\": " << month << ",\n";
    out << "    \"day\": " << day << ",\n";
    out << "    \"hour\": " << hour << ",\n";
    out << "    \"minute\": " << minute << ",\n";
    out << "    \"wday\": " << wday << "\n";
    out << "  }\n";
    out << "}\n";
}
