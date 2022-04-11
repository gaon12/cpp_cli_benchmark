#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstdio>
#include<cmath> //연산
#include <chrono> //시간값 계산
#include <filesystem>
#include "unistd.h"
#include <direct.h> //폴더 삭제
#include <string>
#include <intrin.h> //CPU 이름 불러오기
#include <thread> //CPU 코어 수 불러오기
#include <sstream> //cmd값 변수 저장
#include <stdlib.h> //방화벽 막히는지 확인하기
#include <ctime> //시간/날짜값 가져오기
#define BUFFER_SIZE 1024
//네임스페이스 설정
using namespace std;
using namespace chrono;
//무리수 e 연산 위해 팩토리얼 계산
double factorial(double a);
//파일 다운로드를 위해 추가
#pragma comment(lib, "Urlmon.lib")


//메모리 정보 불러오기 함수
DWORDLONG GetTotalPhysicalMemory()
{
    MEMORYSTATUSEX memStatusEx = { 0 };
    memStatusEx.dwLength = sizeof(MEMORYSTATUSEX);
    BOOL bRet = ::GlobalMemoryStatusEx(&memStatusEx);
    return memStatusEx.ullTotalPhys;
}


void cls(); //화면 초기화 cls 명령어
void splash(); //스플래시 화면
void check_internet(); //인터넷 연결 여부 확인
void terms_download(); //약관 파일 다운로드
void terms_agree(); //약관 동의 여부 확인
void pre_download(); //준비 파일들 다운로드
void console_no_select(); //콘솔창 선택 안되게
void adds(); // 더하기 연산
void pi_calc(); //원주율 연산
void upscale(); //업스케일링 작업
void compress(); //압축/압축 해제 작업
void e_calc(); //무리수 e 연산
void decrypt_zip(); //암호걸린 압축파일 암호 찾기
void download_test(); //다운로드 속도 측정
void console_no_select_restore(); //설정 복구
void rm_usefiles(); //사용한 파일들 삭제
void open_result(); //결과 화면 열기


int main() {

    //스플래시 화면
    splash();

    //인터넷 연결 여부 확인
    check_internet();
    
    system("title 벤치마크 - 약관 동의"); //콘솔창 제목 설정

    //약관 다운로드
    terms_download();

    //약관 동의 여부 확인
    terms_agree();

    //필요한 파일들 다운로드
    pre_download();

    //콘솔창 사용자가 선택 못하도록
    console_no_select();

    Sleep(600);
    cout << "현재 수행중인 작업은 다음과 같습니다.\n\n";
    Sleep(800);

    system_clock::time_point StartTime = system_clock::now();//시간 계산 시작

    //파트1 - 1부터 300억까지 더하기
    adds();

    system_clock::time_point FirstPartEndTime = system_clock::now();
    duration<double> DefaultSec = FirstPartEndTime - StartTime;
    milliseconds mill = duration_cast<milliseconds>(FirstPartEndTime - StartTime);
    seconds sec = duration_cast<seconds>(FirstPartEndTime - StartTime);
    cout << mill.count() << "ms" << "(" << sec.count() << "초)";//시간 출력

    //파트2 - 원주율 구하기
    pi_calc();

    system_clock::time_point SecondPartEndTime = system_clock::now();
    duration<double> DefaultSec_second = SecondPartEndTime - FirstPartEndTime;
    milliseconds mill_second = duration_cast<milliseconds>(SecondPartEndTime - FirstPartEndTime);
    seconds sec_second = duration_cast<seconds>(SecondPartEndTime - FirstPartEndTime);
    cout << mill_second.count() << "ms" << "(" << sec_second.count() << "초)";//시간 출력

    //파트3 - 업스케일링 30배
    upscale();

    system_clock::time_point ThirdPartEndTime = system_clock::now();
    duration<double> DefaultSec_Third = ThirdPartEndTime - SecondPartEndTime;
    milliseconds mill_third = duration_cast<milliseconds>(ThirdPartEndTime - SecondPartEndTime);
    seconds sec_third = duration_cast<seconds>(ThirdPartEndTime - SecondPartEndTime);
    cout << mill_third.count() << "ms" << "(" << sec_third.count() << "초)";//시간 출력

    //파트4 - 압축/압축 해제
    compress();

    system_clock::time_point FourthPartEndTime = system_clock::now();
    duration<double> DefaultSec_Fourth = FourthPartEndTime - ThirdPartEndTime;
    milliseconds mill_fourth = duration_cast<milliseconds>(FourthPartEndTime - ThirdPartEndTime);
    seconds sec_fourth = duration_cast<seconds>(FourthPartEndTime - ThirdPartEndTime);
    cout << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)";//시작 출력

    //파트5 - 무리수 e 구하기
    e_calc();

    system_clock::time_point FifthPartEndTime = system_clock::now();
    duration<double> DefaultSec_Fifth = FifthPartEndTime - FourthPartEndTime;
    milliseconds mill_fifth = duration_cast<milliseconds>(FifthPartEndTime - FourthPartEndTime);
    seconds sec_fifth = duration_cast<seconds>(FifthPartEndTime - FourthPartEndTime);
    cout << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)";//시작 출력

    //파트6 - 암호걸린 압축파일 비밀번호 찾기
    decrypt_zip();

    //파트6을 진행하면 진행 과정이 화면에 나오기 때문에, 완료되면 바로 화면을 지우고 기존 값으로 덮어씌웁니다.
    cls();

    system_clock::time_point SixthPartEndTime = system_clock::now();
    duration<double> DefaultSec_Sixth = SixthPartEndTime - FifthPartEndTime;
    milliseconds mill_sixth = duration_cast<milliseconds>(SixthPartEndTime - FifthPartEndTime);
    seconds sec_sixth = duration_cast<seconds>(SixthPartEndTime - FifthPartEndTime);

    //파트6을 진행하면 진행 과정이 화면에 나오기 때문에, 완료되면 바로 화면을 지우고 기존 값으로 덮어씌웁니다.
    cls();

    cout << "1. 1부터 300억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(40배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력
    cout << "4. 압축/압축 해제 작업 : " << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)\n";//시작 출력
    cout << "5. 무리수 e 구하기 : " << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)\n";//시작 출력
    cout << "6. 압축파일 암호 풀기 : " << mill_sixth.count() << "ms" << "(" << sec_sixth.count() << "초)\n";//시작 출력

    //번외 테스트는 총 시간에 포함시키지 않기 위해 시점 조정
    system_clock::time_point EndTime = system_clock::now();

    //번외 테스트(다운로드 시간)
    system_clock::time_point ExtraTestStartTime = system_clock::now();//시간 계산 시작

    //번외 - 다운로드 속도 측정
    download_test();

    system_clock::time_point ExtraTestEndTime = system_clock::now();
    duration<double> DefaultSec_Extra = ExtraTestEndTime - ExtraTestStartTime;
    milliseconds mill_extra = duration_cast<milliseconds>(ExtraTestEndTime - ExtraTestStartTime);
    seconds sec_extra = duration_cast<seconds>(ExtraTestEndTime - ExtraTestStartTime);
    cout << mill_extra.count() << "ms" << "(" << sec_extra.count() << "초)";//시작 출력

    //결과 시간 측정
    duration<double> DefaultSec_end = EndTime - StartTime;
    milliseconds mill_end = duration_cast<milliseconds>(EndTime - StartTime);
    seconds sec_end = duration_cast<seconds>(EndTime - StartTime);
    minutes min_end = duration_cast<minutes>(EndTime - StartTime);

    system("title 벤치마크 - 완료!"); //콘솔창 제목 설정
    cout << "\n총 수행시간 : ";

    int min, hour;
    min = sec_end.count() / 60;
    hour = min / 60;
    min = min % 60;

    cout << mill_end.count() << "ms (" << sec_end.count() << "초)";//시간 출력
    cout << "총 걸린 시간은 " << hour << "시간 " << min << "분 " << sec_end.count() % 60 << "초 입니다.";

    //PC 사양 정보 읽기
    //CPU 이름 불러오기
    int CPUInfo[4] = { -1 };
    unsigned   nExIds, indexs = 0;
    char CPUBrandString[0x40];
    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (indexs = 0x80000000; indexs <= nExIds; ++indexs)
    {
        __cpuid(CPUInfo, indexs);
        // Interpret CPU brand string
        if (indexs == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (indexs == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (indexs == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    //string includes manufacturer, model and clockspeed
    //띄어쓰기를 _(언더바)로 변경
    for (int chub = 0; CPUBrandString[chub]; chub++) {
        if (CPUBrandString[chub] == ' ') CPUBrandString[chub] = '_';
    }

    //RAM 정보 불러오기
    const DWORD dwMBFactor = 0x00100000;
    DWORDLONG dwTotalPhys = GetTotalPhysicalMemory();

    //GPU 정보 불러오기
    system("get_gpu_name.bat > 1.txt");

    char gpu_info[1000];
    FILE* fptr;
    if ((fptr = fopen("1.txt", "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", gpu_info);

    string gpu_info_ncut(gpu_info);

    string gpu_name_info = gpu_info_ncut.substr(7); //맨 앞에 Name : 부분 삭제
    //띄어쓰기를 _(언더바)로 변경
    for (int chub2 = 0; gpu_name_info[chub2]; chub2++) {
        if (gpu_name_info[chub2] == ' ') gpu_name_info[chub2] = '_';
    }

    char gpu_name_raw[100];
    strcpy(gpu_name_raw, gpu_name_info.c_str()); //string값인 gpu 정보를 char로 변환

    //현재 날짜 및 시간값 불러오기
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    char year[50] = { 0x00, }, month[50] = { 0x00, }, day[50] = { 0x00, }, hours[50] = { 0x00, }, minute[50] = { 0x00, }, wday[50] = { 0x00, };

    sprintf(year, "%d", t->tm_year + 1900);
    sprintf(month, "%d", t->tm_mon + 1);
    sprintf(day, "%d", t->tm_mday);
    sprintf(hours, "%d", t->tm_hour);
    sprintf(minute,"%d", t->tm_min);
    sprintf(wday, "%s", t->tm_wday);


    //결과값 저장

    /*
    결과값 출력, PC 사양 정보, 시간값 출력을 위해
    결과 내용을 important_values.js에 저장합니다.

    결과값은 이미 저장되어 있지만, PC 사양 정보는 아직 읽어오지 않았기 때문에
    저장하기 전에 PC 사양 정보를 먼저 읽어옵니다.

    저장되는 값은 다음과 같습니다.

    [PC 사양]
    * CPU 이름
    * 램 용량(물리)
    * GPU 이름

    [결과값(시간값만)]
    * 1부터 300억까지 더하기
    * 원주율(π) 구하기
    * waifu2x-converter-cpp로 업스케일링
    * 압축/압축해제
    * 무리수 e 구하기
    * 다운로드 속도 측정
    
    [날짜 및 시간]
    * 벤치마크를 돌린 날 기준으로 날짜와 시간

    */

    FILE* fpjs = 0;
    fopen_s(&fpjs, "important_values.js", "w");    // score.js 파일을 쓰기 모드(w)로 열기.
                                      // 파일 포인터를 반환

    char plus_time[70] = "var plus_time =";
    char pi_time[70] = "var pi_time =";
    char download_time[70] = "var download_time =";
    char upscale_time[70] = "var upscale_time =";
    char compress_time[70] = "var compress_time =";
    char surd_e_time[70] = "var surd_e_time =";
    char decrypt_zip_time[70] = "var decrypt_zip_time =";

    char ch_plus_time[100];
    string st_plus_time = to_string(mill.count());
    strcpy(ch_plus_time, st_plus_time.c_str());

    char ch_pi_time[100];
    string st_pi_time = to_string(mill_second.count());
    strcpy(ch_pi_time, st_pi_time.c_str());

    char ch_upscale_time[100];
    string st_upscale_time = to_string(mill_third.count());
    strcpy(ch_upscale_time, st_upscale_time.c_str());

    char ch_compress_time[100];
    string st_compress_time = to_string(mill_fourth.count());
    strcpy(ch_compress_time, st_compress_time.c_str());

    char ch_surd_e_time[100];
    string st_surd_e_time = to_string(mill_fifth.count());
    strcpy(ch_surd_e_time, st_surd_e_time.c_str());

    char ch_decrypt_zip_time[100];
    string st_decrypt_zip_time = to_string(mill_sixth.count());
    strcpy(ch_decrypt_zip_time, st_decrypt_zip_time.c_str());

    char ch_download_time[100];
    string st_download_time = to_string(mill_extra.count());
    strcpy(ch_download_time, st_download_time.c_str());

    fputs(strcat(plus_time, ch_plus_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(pi_time, ch_pi_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(download_time, ch_download_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(upscale_time, ch_upscale_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(compress_time, ch_compress_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(surd_e_time, ch_surd_e_time), fpjs);
    fputs(";\n", fpjs);
    fputs(strcat(decrypt_zip_time, ch_decrypt_zip_time), fpjs);
    fputs(";\n", fpjs);

    //PC 정보 추가
    //CPU 이름 추가
    char cpu_name[70] = "var cpu_name = \"";
    fputs(strcat(cpu_name, CPUBrandString), fpjs);
    fputs("\";\n", fpjs);

    //RAM 크기 추가
    char ram_size[70] = "var ram_size = ";
    DWORD DTotalRamSize = dwTotalPhys / dwMBFactor / 1000;
    //DWORD를 char로 변환
    char TotalRamSize[10];
    sprintf(TotalRamSize, "%d", DTotalRamSize);
    fputs(strcat(ram_size, TotalRamSize), fpjs);
    fputs(";\n", fpjs);

    //GPU 이름 추가
    char gpu_name[70] = "var gpu_name = \"";
    fputs(strcat(gpu_name, gpu_name_raw), fpjs);
    fputs("\b\";\n", fpjs);

    //현재 날짜 추가
    char now_date_year[70] = "var now_date_year = \"";
    fputs(strcat(now_date_year, year), fpjs);
    fputs("\b\";\n", fpjs);

    char now_date_month[70] = "var now_date_month = \"";
    fputs(strcat(now_date_month, month), fpjs);
    fputs("\b\";\n", fpjs);

    char now_date_day[70] = "var now_date_day = \"";
    fputs(strcat(now_date_day, day), fpjs);
    fputs("\b\";\n", fpjs);

    char now_date_hours[70] = "var now_date_hours = \"";
    fputs(strcat(now_date_hours, hours), fpjs);
    fputs("\b\";\n", fpjs);

    char now_date_minute[70] = "var now_date_minute = \"";
    fputs(strcat(now_date_minute, minute), fpjs);
    fputs("\b\";\n", fpjs);

    char now_date_wday[70] = "var now_date_wday = \"";
    fputs(strcat(now_date_wday, wday), fpjs);
    fputs("\b\";\n", fpjs);

    fclose(fpjs);    // 파일 포인터 닫기

    //콘솔창 선택 못하도록 했던 설정 복구
    console_no_select_restore();

    //사용한 파일들 삭제
    system("title 사용한 파일들을 삭제합니다. 잠시만 기다려 주세요!"); //콘솔창 제목 설정
    rm_usefiles();

    //결과 페이지 열기
    system("title 결과 페이지에서 벤치마크 결과를 확인하세요!"); //콘솔창 제목 설정
    open_result();
}

void cls()
{
    system("cls");
}

void splash()
{
    cout << "\t\t\t\t\t   _                     _\n";
    cout << "\t\t\t\t\t _|_|___________________|_|_\n";
    cout << "\t\t\t\t\t|__:_____________________:__|\n";
    cout << "\t\t\t\t\t|___________________________|\n";
    cout << "\t\t\t\t\t|__:_____________________:__|\n";
    cout << "\t\t\t\t\t|___________________________|\n";
    cout << "\t\t\t\t\t  |_|___________________|_|\n";
    cout << "\t\t\t\t\t /__.___________________.__\"\n";
    cout << "\t\t\t\t\t/__._____________________.__\"\n";
    cout << "\t\t\t\t\t/____________________________\"\n";
    cout << "\t\t\t\t\t   | |_|               |_| |\n";
    cout << "\t\t\t\t\t   | |                   | |\n";
    cout << "\t\t\t\t\t   | |                   | |\n";
    cout << "\t\t\t\t\t   |_|                   |_|lc\n\n";

    cout << "\t\t\t\t벤치마크 프로그램에 오신것을 환영합니다!\n";
    cout << "\t\t\t\t인터넷 연결 여부를 확인하고 있습니다.\n";
    cout << "\t\t\t\t\t잠시만 기다려 주세요!\n";
    Sleep(3000);
    cls();
}

void check_internet()
{
    //방화벽에 막히는지 확인
    char buffer[BUFFER_SIZE] = { 0 };
    FILE* pipe = _popen("ping 1.1.1.1 -n 2", "rt"); //1.1.1.1(클라우드플레어 DNS 서버)로 핑을 보닙니다.
    if (pipe != NULL) {
        int rd = 0, ret;
        while ((ret = fread(buffer + rd, 1, BUFFER_SIZE - rd, pipe)) > 0) {
            rd += ret;
        }

        if (strstr(buffer, "TTL=") != NULL) { //인터넷에 연결이 되어 있는 경우
            cout << "\n\t\t\t\t 인터넷에 연결되어 있습니다. 방화벽에도 막혀있지 않습니다.\n\t\t\t\t 정상적으로 프로그램을 사용할 수 있습니다.\n";
            Sleep(3000);
            cls();
        }
        else {//인터넷에 연결이 안되어 있는 경우
            cout << "\n\t\t\t\t 인터넷에 연결되어 있지 않거나 방화벽에 차단되어 있습니다.\n\t\t\t\t 정상적인 프로그램 사용을 위해 인터넷을 연결하거나 방화벽에서 본 프로그램을 차단 해제해 주세요!\n 10초 뒤 프로그램이 자동 종료됩니다.";
            Sleep(10000);
            exit(0);
        }
        //printf( "%d bytes read\n\n%s\n", rd, buffer );
        _pclose(pipe);
    }
    else //명령어 실행에 실패한 경우
    {
        cout << "Error in pipe opening!\n";
        cls();
    }
}

void terms_download()
{
    /*
    약관 동의 페이지
    프로그램이 멈추거나, 심하면 OS가 작동 중지 될 수도(사양이 낮을 경우) 있기 때문에, 약관에 동의하는 것을 추가합니다.
    약관 내용은 txt 파일을 불러오는 것으로 하였습니다.
    */
    //약관 파일을 다운로드 합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/prj/cpp_cli_benchmark/terms.txt", L"terms.txt", 0, NULL); //약관 파일을 다운로드합니다.
}

void terms_agree()
{
    cout << "---------------------------------------------------------------------------------------------\n";
    //약관 파일을 엽니다.
    FILE* fp = 0;
    char text[100];
    setlocale(LC_ALL, "korean");
    fopen_s(&fp, "terms.txt", "r"); //약관 파일 열기
    while (1) {
        fgets(text, 100, fp);
        printf("%s\n", text);
        if (feof(fp)) break;
    }
    fclose(fp); //파일 닫기
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "\n\n 약관에 동의하십니까? 동의하시면 \"1\"을, 종료는 \"2\"를 입력해 주세요.";

    while (1)
    {
        int terms_agree;
        cin >> terms_agree;
        if (terms_agree == 1) {
            cls();
            break;
        }
        else if (terms_agree == 2) {
            cls();
            cout << "5초 뒤 종료됩니다.";
            Sleep(5000);
            exit(0);
        }
        else {
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
            cls();
        }
    }
}

void pre_download()
{
    system("title 벤치마크 - 필요한 파일들 다운로드 중..."); //콘솔창 제목 설정
    cout << "벤치마크 프로그램입니다.\n필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n";
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/7-Zip/7z.exe", L"7z.exe", 0, NULL); //7z.exe를 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/7-Zip/7z.dll", L"7z.dll", 0, NULL); //7z.exe이 동작하는데 필요한 파일인 7z.dll 파일을 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/prj/cpp_cli_benchmark/all.7z", L"all.7z", 0, NULL); //waifu2x, 테스트용 압축 파일이 담긴 압축파일을 다운로드합니다.
    system("@echo off && 7z x all.7z > 1.txt"); //다운로드 받은 파일을 압축해제합니다.
    URLDownloadToFile(NULL, L"https://i.ibb.co/1b2Ns1b/aki.png", L"aki.png", 0, NULL);//크기가 작은 이미지 파일을 다운로드합니다.
    cls();
}

void console_no_select() {
    system("console_no_select.bat > 1.txt");
}

void adds()
{
    system("title 벤치마크 - (연산) 1부터 600억까지 더하기"); //콘솔창 제목 설정
    cout << "1. 1부터 300억까지 더하기 : ";

    long sum = 0;

    long long i = 0;
    long long sums = 0;
    for (i = 1; i <= 30000000000; i++) { //1부터 30000000000까지 반복
        sums += i; //sums=sums+i
    }
}

void pi_calc()
{
    system("title 벤치마크 - (연산) 원주율 구하기"); //콘솔창 제목 설정
    cout << "\n2. 원주율 구하기 : ";

    double pi = 0.0, num = 1.0;

    while (num < 1000000000)
    {
        pi += 1.0 / pow(num, 2.0);
        num += 1.0;
    }
}

void upscale()
{
    system("title 벤치마크 - (작업) waifu2x 40배 업스케일링 작업"); //콘솔창 제목 설정
    cout << "\n3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(40배) : ";

    system("@echo off && waifu2x-converter-cpp  --scale-ratio 40 -i aki.png -o aki_out.png > 1.txt");
}

void compress()
{
    system("title 벤치마크 - (작업) 압축/압축 해제 작업"); //콘솔창 제목 설정
    cout << "\n4. 압축/압축 해제 작업 : ";

    /*
    압축과 압축 해제 작업입니다. 아래의 순서대로 작업이 이루어집니다.

    1. 먼저 실행되고 있는 PC의 CPU 스레드 수를 획득합니다.
    2. 그리고 7z를 이용하여 다운로드 받은 zip.7z를 압축해제 합니다.
    3. 2의 작업으로 얻은 zip 폴더를 test.7z라는 파일로 압축합니다. 이때 압축시 아까 얻은 CPU 스레드 수만큼 압축 작업을 합니다.
       (즉, 모든 스레드가 압축하는데 사용하도록 합니다.)
    4. 마찬가지로 2의 작업으로 얻은 zip 폴더를 test.zip이라는 파일로 압축합니다. 마찬가지로 모든 스레드를 압축 작업에 사용합니다.
    5. zip 폴더를 삭제합니다. test.zip 파일을 압축해제하면 zip폴더가 생성이 되기 때문에 압축해제 하기 전에 zip 폴더를 삭제합니다.
    6. 4의 작업으로 얻은 test.zip을 압축해제합니다.
    */
    
    //PC의 스레드 수를 구합니다.
    SYSTEM_INFO siSysInfo; // Copy the hardware information to the SYSTEM_INFO structure. 
    GetSystemInfo(&siSysInfo); // Display the contents of the SYSTEM_INFO structure. 

    char cmd1[100];
    char cmd2[100];
    system("7z x -bd zip.7z > 1.txt"); //zip.7z 파일을 압축해제합니다.
    sprintf_s(cmd1, "7z a -t7z -mmt%u -mx9 test.7z \"zip\" > 1.txt", siSysInfo.dwNumberOfProcessors); //zip 폴더를 7z로 압축합니다.
    system(cmd1);
    sprintf_s(cmd2, "7z a -tzip -mmt%u -mx9 test.zip \"zip\" > 1.txt", siSysInfo.dwNumberOfProcessors); //zip 폴더를 zip으로 압축합니다.
    system(cmd2);
    system("del /s /q zip > 1.txt");
    system("7z x -bd zip.7z > 1.txt");
}

void e_calc()
{
    system("title 벤치마크 - (연산) 무리수 e 구하기"); //콘솔창 제목 설정
    cout << "\n5. 무리수 e 구하기 : ";

    int ntimes = 130000;
    int add;
    double j, surd_e;
    surd_e = 1;

    for (add = 1; add <= ntimes; add++)
    {
        j = 1 / factorial(add);
        surd_e = surd_e + j;
    }
}

void decrypt_zip() {
    system("title 벤치마크 - (작업) 압축파일 암호 풀기"); //콘솔창 제목 설정
    cout << "\n6. 압축파일 암호 풀기 : ";

    system("@echo off && cd john && zip2john test.zip > hash.txt && john hash.txt > 1.txt");
}

void download_test()
{
    system("title 벤치마크 - (작업) 파일 다운로드 속도 측정"); //콘솔창 제목 설정
    cout << "\n번외 - 파일 다운로드 속도 측정 : ";

    URLDownloadToFile(NULL, L"https://sel-kor-ping.vultr.com/vultr.com.1000MB.bin", L"./testfile.bin", 0, NULL);
}

void console_no_select_restore() {
    system("console_no_select_restore.bat > 1.txt");
}

void rm_usefiles()
{
    system("@echo off && del terms.txt 7z.exe 7z.dll all.7z waifu2x-converter-cpp.exe w2xc.dll opencv_world430.dll LICENSE aki.png aki_out.png testfile.bin test.zip test.7z zip.7z terms.txt get_gpu_name.bat decrypt_zip.bat console_no_select.bat console_no_select_restore.bat > 1.txt");
    system("@echo off && rmdir /s /q models_rgb > 1.txt"); //폴더는 따로 삭제합니다.
    system("@echo off && rmdir /s /q zip > 1.txt");
    system("@echo off && rmdir /s /q john > 1.txt");

    remove("1.txt");
}

void open_result()
{
    cout << "5초 뒤 결과가 나옵니다. 결과창을 확인하세요!";
    system("start /max index.html");
}

double factorial(double a) //팩토리얼 연산
{
    double add, j;
    j = 1;
    for (add = 1; add <= a; add++)
    {
        j = j * add;
    }
    return j;
}