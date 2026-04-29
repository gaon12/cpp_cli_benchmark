#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstdio>
#include<cmath> //연산
#include <chrono> //시간값 계산
#include <filesystem>
#include <direct.h> //폴더 삭제
#include <string>
#include <intrin.h> //CPU 이름 불러오기
#include <thread> //CPU 코어 수 불러오기
#include <sstream> //cmd값 변수 저장
#include <stdlib.h> //방화벽 막히는지 확인하기
#include <ctime> //시간/날짜값 가져오기
#include <limits>
#include <cstring>
#include <fstream>
#include <atomic>
#include "benchmark_app.hpp"
#include "report/runtime_utils.hpp"
#include "platform/windows/runtime.hpp"

#define BUFFER_SIZE 1024
//네임스페이스 설정
using namespace std;
using namespace chrono;
//무리수 e 연산 위해 팩토리얼 계산
double factorial(double a);
//파일 다운로드를 위해 추가
#pragma comment(lib, "Urlmon.lib")

//메뉴별 이동 가능하도록 체크하는 변수 생성
int check = 0;

//윈도우 비트 확인
int x64 = 1;

//매운맛 정도
int scoville = 0;

//유틸리티(다용도)
void cls(); //화면 초기화 cls 명령어

void introduction(); //벤치마크 작동 전 공통으로 들어가는 항목을 모아둔 함수
void splash(); //스플래시 화면
void check_internet(); //인터넷 연결 여부 확인
void update_check(); //업데이트 확인
void terms_download(); //약관 파일 다운로드
void terms_agree(); //약관 동의 여부 확인
void help_document(); //도움말 문서

int choose_level(); //매운맛 정도를 선택하는 함수

void common_pre_download(); //공통 준비 파일들 다운로드

//순한맛용 벤치마크 과정
void mild(); //아래의 과정들을 모아둔 과정
void mild_pre_download(); //준비 파일들 다운로드
void mild_adds(); // 더하기 연산
void mild_pi_calc(); //원주율 연산
void mild_upscale(); //업스케일링 작업
//void mild_compress(); //압축/압축 해제 작업 파트. 명령어는 동일하므로 따로 함수 생성 안함.
void mild_e_calc(); //무리수 e 연산
//void mild_decrypt_zip(); //암호걸린 압축파일 암호 찾기 명령어는 동일하므로 따로 함수 생성 안함.
void mild_download_test(); //다운로드 속도 측정

//보통맛용 벤치마크 과정
void normal(); //아래의 과정들을 모아둔 과정
void pre_download(); //준비 파일들 다운로드
void adds(); // 더하기 연산
void pi_calc(); //원주율 연산
void upscale(); //업스케일링 작업
void compress(); //압축/압축 해제 작업
void e_calc(); //무리수 e 연산
void decrypt_zip(); //암호걸린 압축파일 암호 찾기
void download_test(); //다운로드 속도 측정

//매운맛용 벤치마크 과정
void spicy(); //아래의 과정들을 모아둔 과정
void spicy_pre_download(); //준비 파일들 다운로드
void spicy_adds(); // 더하기 연산
void spicy_pi_calc(); //원주율 연산
void spicy_upscale(); //업스케일링 작업
//void spicy_compress(); //압축/압축 해제 작업 명령어는 동일하므로 따로 함수 생성 안함.
void spicy_e_calc(); //무리수 e 연산
//void spicy_decrypt_zip(); //암호걸린 압축파일 암호 찾기 명령어는 동일하므로 따로 함수 생성 안함.
void spicy_download_test(); //다운로드 속도 측정

void conclusion(); // 벤치마크 완료 후 결과 화면 출력까지의 과정을 모아둔 함수
void rm_usefiles(); //사용한 파일들 삭제
void open_result(); //결과 화면 열기
void exit_countdown(); //종료시 카운트다운

volatile long double g_bench_sink = 0.0;

/*
void br(); //입력한 값만큼 줄 개행(줄바꿈)
void progress(); //입력한 값만큼 퍼센테이지 표시
*/

void br(int a)
{
    for (int i = 0; i < a; i++)
    {
        cout << endl;
    }
}


void progress(int b)
{
    int k = 100 - b;

    cout << "[";
    for (int i = 0; i < b; i++)
        cout << "#";
    for (int j = 0; j < k; j++)
        cout << ".";

    cout << "] " << b << "%%" << endl;
}
int run_benchmark_app()
{
    rm_usefiles();
    cls();

    introduction();

    choose_level();

    //마무리
    conclusion();
    return 0;
}

#include "chunks/setup_and_menu.inc"
#include "chunks/level_mild.inc"
#include "chunks/level_normal.inc"
#include "chunks/level_spicy.inc"
#include "chunks/work_tasks.inc"
