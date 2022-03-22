#include <iostream>
#include <windows.h>
#include <cstdio>
#include<cmath>
#pragma comment(lib, "Urlmon.lib")
#include <chrono>
#include <filesystem>
#include <winbase.h>
using namespace std;

int main() {
    system("title 벤치마크 - 약관 동의"); //콘솔창 제목 설정

    /*
    약관 동의 페이지
    프로그램이 멈추거나, 심하면 OS가 작동 중지 될 수도(사양이 낮을 경우) 있기 때문에, 약관에 동의하는 것을 추가합니다.
    약관 내용은 txt 파일을 불러오는 것으로 하였습니다.
    */

    URLDownloadToFile(NULL, L"https://common.gaon.xyz/prj/cpp_cli_benchmark/terms.txt", L"terms.txt", 0, NULL); //약관 파일을 다운로드합니다.

TERMS:

    char buffer[20];    // 파일을 읽을 때 사용할 임시 공간
    FILE* fp = fopen("terms.txt", "r");    // terms.txt 파일을 읽기 모드로 열기.  
                                           // 파일 포인터를 반환

    fgets(buffer, sizeof(buffer), fp);    // terms.txt에서 문자열을 읽음
    printf("%s\n", buffer);    // 파일의 내용 출력

    fclose(fp);    // 파일 포인터 닫기

    std::cout << "\n\n약관에 동의하십니까? 동의하시면 Y를 입력해 주십시오.    " << std::endl;

    char terms_agree;
    scanf_s("%c", &terms_agree, 50);
    if (terms_agree == 'Y' || terms_agree == 'y') {
        goto START;
    }
    else {
        system("cls");
        std::cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!" << std::endl;
        goto TERMS;
    }

START:
    
    system("cls");

    std::cout << "벤치마크 프로그램입니다.\n필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n" << std::endl;
    std::cout << "방화벽 등의 프로그램에서 차단하고 있다면 예외 처리해 주세요!\n\n" << std::endl;
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/7-Zip/7z.exe", L"7z.exe", 0, NULL); //7z.exe를 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/7-Zip/7z.dll", L"7z.dll", 0, NULL); //7z.exe이 동작하는데 필요한 파일인 7z.dll 파일을 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/waifu2x/waifu2x-converter-cpp/wcc.zip", L"wcc.zip", 0, NULL); //waifu2x cpp 버전을 다운로드합니다.
    system("@echo off && 7z x wcc.zip > 1.txt"); //다운로드 받은 파일을 압축해제합니다.
    URLDownloadToFile(NULL, L"https://i.ibb.co/1b2Ns1b/aki.png", L"aki.png", 0, NULL);//크기가 작은 이미지 파일을 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/prj/cpp_cli_benchmark/zip.7z", L"zip.7z", 0, NULL); //테스트용 압축 파일을 다운로드합니다.
    Sleep(600);
    std::cout << "현재 수행중인 작업은 다음과 같습니다.\n\n" << std::endl;
    Sleep(800);

    system("title 벤치마크 - (연산) 1부터 600억까지 더하기"); //콘솔창 제목 설정

    std::cout << "1. 1부터 600억까지 더하기" << std::endl;
    
    long sum = 0;
    chrono::system_clock::time_point StartTime = chrono::system_clock::now();//시간 계산 시작
    
    long long i = 0;
    long long sums = 0;
    for (i = 1; i <= 60000000000; i++) { //1부터 60000000000까지 반복
        sums += i; //sums=sums+i
    }
    
    chrono::system_clock::time_point FirstPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec = FirstPartEndTime - StartTime;
    chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(FirstPartEndTime - StartTime);
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(FirstPartEndTime - StartTime);
    cout << mill.count() << "ms" << "(" << sec.count() << "초)" << endl;//시간 출력
    
    system("title 벤치마크 - (연산) 원주율 구하기"); //콘솔창 제목 설정

    std::cout << "\n2. 원주율 구하기 : " << std::endl;

    double pi = 0.0, num = 1.0;

    while (num < 2000000000)
    {
        pi += 1.0 / pow(num, 2.0);
        num += 1.0;
    }
    
    chrono::system_clock::time_point SecondPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_second = SecondPartEndTime - FirstPartEndTime;
    chrono::milliseconds mill_second = chrono::duration_cast<chrono::milliseconds>(SecondPartEndTime - FirstPartEndTime);
    chrono::seconds sec_second = chrono::duration_cast<chrono::seconds>(SecondPartEndTime - FirstPartEndTime);
    cout << mill_second.count() << "ms" << "(" << sec_second.count() << "초)" << endl;//시간 출력
    
    system("title 벤치마크 - (작업) 파일 다운로드 속도 측정"); //콘솔창 제목 설정

    std::cout << "\n3. 파일 다운로드 속도 측정 : " << std::endl;

    URLDownloadToFile(NULL, L"https://sel-kor-ping.vultr.com/vultr.com.1000MB.bin", L"./testfile.bin", 0, NULL);
    
    chrono::system_clock::time_point ThirdPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_Third = ThirdPartEndTime - SecondPartEndTime;
    chrono::milliseconds mill_third = chrono::duration_cast<chrono::milliseconds>(ThirdPartEndTime - SecondPartEndTime);
    chrono::seconds sec_third = chrono::duration_cast<chrono::seconds>(ThirdPartEndTime - SecondPartEndTime);
    cout << mill_third.count() << "ms" << "(" << sec_third.count() << "초)" << endl;//시간 출력

    system("title 벤치마크 - (작업) waifu2x 40배 업스케일링 작업"); //콘솔창 제목 설정

    std::cout << "\n4. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(40배) : " << std::endl;
    system("@echo off && waifu2x-converter-cpp  --scale-ratio 40 -i aki.png -o aki_out.png > 1.txt");

    chrono::system_clock::time_point FourthPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_Fourth = FourthPartEndTime - ThirdPartEndTime;
    chrono::milliseconds mill_fourth = chrono::duration_cast<chrono::milliseconds>(FourthPartEndTime - ThirdPartEndTime);
    chrono::seconds sec_fourth = chrono::duration_cast<chrono::seconds>(FourthPartEndTime - ThirdPartEndTime);
    cout << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)" << endl;//시작 출력

    system("title 벤치마크 - (작업) 압축/압축 해제 작업"); //콘솔창 제목 설정

    std::cout << "\n5. 압축/압축 해제 작업 : " << std::endl;
    
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

    chrono::system_clock::time_point FifthPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_Fifth = FifthPartEndTime - FourthPartEndTime;
    chrono::milliseconds mill_fifth = chrono::duration_cast<chrono::milliseconds>(FifthPartEndTime - FourthPartEndTime);
    chrono::seconds sec_fifth = chrono::duration_cast<chrono::seconds>(FifthPartEndTime - FourthPartEndTime);
    cout << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)" << endl;//시작 출력

    chrono::system_clock::time_point EndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_end = EndTime - StartTime;
    chrono::milliseconds mill_end = chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime);
    chrono::seconds sec_end = chrono::duration_cast<chrono::seconds>(EndTime - StartTime);
    chrono::minutes min_end = chrono::duration_cast<chrono::minutes>(EndTime - StartTime);

    std::cout << "\n총 수행시간 : " << std::endl;
    cout << mill_end.count() << "ms (" << sec_end.count() << "초)" << endl;//시간 출력

    //사용한 파일들 삭제
    system("@echo off && del terms.txt 7z.exe 7z.dll wcc.zip waifu2x-converter-cpp.exe w2xc.dll opencv_world430.dll LICENSE aki.png aki_out.png testfile.bin test.zip test.7z zip.7z > 1.txt");
    system("@echo off && del /s /q models_rgb > 1.txt"); //폴더는 따로 삭제합니다.
    system("@echo off && del /s /q zip > 1.txt");

    char filename1[] = "1.txt";

    int r;

    r = _unlink(filename1);
}