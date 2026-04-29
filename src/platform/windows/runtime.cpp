#include <windows.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "platform/windows/runtime.hpp"

using namespace std;

DWORDLONG GetTotalPhysicalMemory()
{
    MEMORYSTATUSEX memStatusEx = { 0 };
    memStatusEx.dwLength = sizeof(MEMORYSTATUSEX);
    BOOL bRet = ::GlobalMemoryStatusEx(&memStatusEx);
    (void)bRet;
    return memStatusEx.ullTotalPhys;
}

void cls()
{
    system("cls");
}

void rm_usefiles()
{
    system("@echo off && del terms.txt 7z.exe 7z.dll waifu2x-converter-cpp.exe w2xc.dll opencv_world430.dll LICENSE aki.png aki_out.png test.zip test.7z zip.7z terms.txt get_gpu_name.bat decrypt_zip.bat latest_version_info.txt > 1.txt");
    system("@echo off && rmdir /s /q models_rgb > 1.txt");
    system("@echo off && rmdir /s /q zip > 1.txt");
    system("@echo off && rmdir /s /q john > 1.txt");

    char rm_log[] = "1.txt";
    char rm_mild_down[] = "cmdtools.zip";
    char rm_normal_down[] = "android_studio.exe";
    char rm_spicy_down[] = "gmaven.zip";
    char rm_mild_all[] = "mildalls.7z";
    char rm_normal_all[] = "all.7z";
    char rm_spicy_all[] = "spicyall.7z";
    remove(rm_log);
    remove(rm_mild_down);
    remove(rm_normal_down);
    remove(rm_spicy_down);
    remove(rm_mild_all);
    remove(rm_normal_all);
    remove(rm_spicy_all);
}

void open_result()
{
    cout << "\n\n5초 뒤 결과가 나옵니다. 결과창을 확인하세요!";
    system("start /max index.html");
}

void conclusion()
{
    rm_usefiles();
    open_result();
}

void exit_countdown()
{
    cls();
    cout << "\n\t\t\t\t\t\t5초 뒤 종료됩니다.\n";
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t4초 뒤 종료됩니다.\n";
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t3초 뒤 종료됩니다.\n";
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t2초 뒤 종료됩니다.\n";
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t1초 뒤 종료됩니다.\n";
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t종료!\n";
    exit(0);
}
