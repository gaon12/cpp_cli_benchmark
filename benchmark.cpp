#include <iostream>
#include <windows.h>
#include <iomanip>
//setprecision() 함수 정의
#include <stdio.h>
#include<cmath>
#pragma comment(lib, "Urlmon.lib")
#include <chrono>
#include <wincrypt.h>
#include <filesystem>
using namespace std;

int main()
{
    /*
    실행 전 잔류 파일을 삭제합니다.
    */
    char filename1[] = "pi.txt";
    char filename2[] = "testfile.bin";
    char filename3[] = "abcd.mp4";
    char filename4[] = "ffmpeg.bat";
    char filename5[] = "ffmpeg_bg.vbs";
    char filename6[] = "ffmpeg.exe";
    char filename7[] = "output.mp4";
    
    int r;
    int re;
    int rem;
    int remo;
    int remov;
    int remove;
    int remove_f;

    r = _unlink(filename1);
    re = _unlink(filename2);
    rem = _unlink(filename3);
    remo = _unlink(filename4);
    remov = _unlink(filename5);
    remove = _unlink(filename6);
    remove_f = _unlink(filename7);

    system("title 벤치마크"); //콘솔창 제목 설정

    printf("벤치마크 프로그램입니다.\n필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n");
    printf("방화벽 등의 프로그램에서 차단하고 있다면 예외 처리해 주세요!\n\n");

    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/ffmpeg/ffmpeg.exe", L"ffmpeg.exe", 0, NULL); //ffmpeg.exe를 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/zip/zip.exe", L"zip.exe", 0, NULL); //zip.exe를 다운로드합니다.
    URLDownloadToFile(NULL, L"https://common.gaon.xyz/utils/zip/unzip.exe", L"unzip.exe", 0, NULL); //unzip.exe를 다운로드합니다.

    /*
    ffmpeg에게 명령어를 입력하는 배치파일
    그리고 그 배치파일을 백그라운드로 실행시켜주는 파일을 생성합니다.
    */


    //ffmpeg.bat 파일을 작성합니다.

    FILE* fp = 0;
    fopen_s(&fp, "ffmpeg.bat", "w");

    fputs("@echo off\n", fp);
    fputs("ffmpeg -fflags +discardcorrupt -i abcd.mp4 -vf 'yadif = 0:-1 : 0, scale = 1920 : 1080' -c:v libx264 -preset:v veryfast -crf 22 -movflags +faststart -c:a aac -b:a 160k output.mp4", fp);

    fclose(fp); //파일 포인터 닫기

    //ffmpeg.bat 파일 작성이 완료되었습니다.

    //ffmpeg.vbs 파일을 작성합니다.
    FILE* fp_one = 0;
    fopen_s(&fp_one, "ffmpeg_bg.vbs", "w");

    fputs("Set objShell = CreateObject(\"Shell.Application\")\n", fp_one);
    fputs("objShell.ShellExecute \"ffmpeg.bat\", \" / c lodctr.exe / r\" , \"\", \"runas\", 0", fp_one);

    fclose(fp_one); //파일 포인터 닫기

    //ffmpeg.vbs 파일 작성이 완료되었습니다.

    URLDownloadToFile(NULL, L"https://gitlab.com/gaon12/dummyfile_zip/-/raw/main/2nd_file_hdr.mp4", L"./abcd.mp4", 0, NULL);
    Sleep(600);
    printf("현재 수행중인 작업은 다음과 같습니다.\n\n");
    Sleep(800);
    printf("1. 1부터 30억까지 더하기 : ");
    
    long sum = 0;
    chrono::system_clock::time_point StartTime = chrono::system_clock::now();//시간 계산 시작

    long long i = 0;
    long long sums = 0;
    for (i = 1; i <= 3000000000; i++) { //1부터 3000000000까지 반복
        sums += i; //sums=sums+i
    }

    chrono::system_clock::time_point FirstPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec = FirstPartEndTime - StartTime;
    chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(FirstPartEndTime - StartTime);
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(FirstPartEndTime - StartTime);
    cout << mill.count() << "ms" << "(" << sec.count() << "초)" << endl;//시간 출력

    printf("\n2. 원주율 구하기 : ");

    double pi = 0.0, num = 1.0;

    while (num < 100000000)
    {
        pi += 1.0 / pow(num, 2.0);
        num += 1.0;
    }

    chrono::system_clock::time_point SecondPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_second = SecondPartEndTime - FirstPartEndTime;
    chrono::milliseconds mill_second = chrono::duration_cast<chrono::milliseconds>(SecondPartEndTime - FirstPartEndTime);
    chrono::seconds sec_second = chrono::duration_cast<chrono::seconds>(SecondPartEndTime - FirstPartEndTime);
    cout << mill_second.count() << "ms" << "(" << sec_second.count() << "초)" << endl;//시간 출력

    printf("\n3. 파일 다운로드 속도 계산 : ");

    URLDownloadToFile(NULL, L"https://sel-kor-ping.vultr.com/vultr.com.1000MB.bin", L"./testfile.bin", 0, NULL);

    chrono::system_clock::time_point ThirdPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_Third = ThirdPartEndTime - SecondPartEndTime;
    chrono::milliseconds mill_third = chrono::duration_cast<chrono::milliseconds>(ThirdPartEndTime - SecondPartEndTime);
    chrono::seconds sec_third = chrono::duration_cast<chrono::seconds>(ThirdPartEndTime - SecondPartEndTime);
    cout << mill_third.count() << "ms" << "(" << sec_third.count() << "초)" << endl;//시간 출력

    printf("\n4. 4K 영상 1080p 인코딩 계산 : ");
    system("ffmpeg_bg.vbs");

    chrono::system_clock::time_point FourthPartEndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_Fourth = FourthPartEndTime - ThirdPartEndTime;
    chrono::milliseconds mill_fourth = chrono::duration_cast<chrono::milliseconds>(FourthPartEndTime - ThirdPartEndTime);
    chrono::seconds sec_fourth = chrono::duration_cast<chrono::seconds>(FourthPartEndTime - ThirdPartEndTime);
    cout << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)" << endl;//시작 출력


    chrono::system_clock::time_point EndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec_end = EndTime - StartTime;
    chrono::milliseconds mill_end = chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime);
    chrono::seconds sec_end = chrono::duration_cast<chrono::seconds>(EndTime - StartTime);
    chrono::minutes min_end = chrono::duration_cast<chrono::minutes>(EndTime - StartTime);
    printf("총 수행시간 : ");
    cout << mill_end.count() << "ms" << "(" << sec_end.count() << "초, " << min_end.count() << "분)" << endl;//시간 출력
    
    //사용한 파일들 삭제
    r = _unlink(filename1);
    re = _unlink(filename2);
    rem = _unlink(filename3);
    remo = _unlink(filename4);
    remov = _unlink(filename5);
    remove = _unlink(filename6);
    remove_f = _unlink(filename7);

    Sleep(8000);
}