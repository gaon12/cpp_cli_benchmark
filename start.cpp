#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;

int check = 0;

//윈도우 비트 확인용
const int* pInt = nullptr;

void cls();
void splash();
void menu();
void a32bit_menu();
void a64bit_menu();
void exit_countdown();
void a32bit_user_select_64bit();
void a64bit_user_select_32bit();

int main()
{
    splash();
    Sleep(3000);
    menu();
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
}

void menu()
{
    cls();
    cout << "\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t 원하는 항목을 선택하세요!\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t 1. 32비트용 벤치마크 실행\n";
    cout << "\t\t\t\t\t 2. 64비트용 벤치마크 실행\n";
    cout << "\t\t\t\t\t 3. 프로그램 복구\n";
    cout << "\t\t\t\t\t 0. 프로그램 종료\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\n\n\t\t\t 메뉴를 선택하세요 : ";

    //무한 반복합니다.
    while (1)
    {
        //메뉴를 입력받을 때 저장할 변수를 선언합니다.
        int menu_num;

        //사용자에게 메뉴값을 입력받고, 그 값을 terms_agree 메모리에 저장합니다.
        cin >> menu_num;

        //만약 1번을 입력하면
        if (menu_num == 1) {
            cls();
            a32bit_menu();
            if (check == 1)
                break;
        }
        //만약 2번을 입력하면
        else if (menu_num == 2) {
            cls();
            a64bit_menu();
            if (check == 1)
                break;
        }

        //만약 3번을 입력하면
        else if (menu_num == 3) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t잠시 뒤 복구프로그램이 실행됩니다.\n";
            Sleep(3000);
            system("updater.exe");
            //프로그램을 종료합니다.
            exit(0);
        }

        //만약 0번을 입력하면
        else if (menu_num == 0) {
            cls();
            exit_countdown();
        }
        //메뉴에 없는 값(1 또는 2)을 입력받았을 경우
        else {
            //오류 메시지를 출력합니다.
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
            //화면을 지웁니다.
            cls();
            //while문에 따라 다시 재입력 받습니다.
        }
    }
}

void a32bit_menu()
{
    //윈도우 비트 확인
    if (sizeof(pInt) == 8)
    {
        a64bit_user_select_32bit();
        a64bit_menu();
    }
    //윈도우 비트 확인 끝

    cls();
    cout << "\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t 원하는 항목을 선택하세요! (32비트용)\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t 1. 순한맛 버전 실행\n";
    cout << "\t\t\t\t\t 2. 보통맛 버전 실행\n";
    cout << "\t\t\t\t\t 3. 매운맛 버전 실행\n";
    cout << "\t\t\t\t\t 0. 메인 메뉴로 돌아가기\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\n\n\t\t\t 메뉴를 선택하세요 : ";

    while (1)
    {
        int menu_num;
        cin >> menu_num;
        if (menu_num == 1) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t잠시 뒤 순한맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t진라면은 순한맛보단 매운맛이 더 맛이ㅆ...\n";
            Sleep(3000);
            system("mild_bench_x86.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 2) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t잠시 뒤 보통맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t예상보다 더 매울수 있다는 점, 참고하세요!\n";
            Sleep(3000);
            system("normal_bench_x86.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 3) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t잠시 뒤 매운맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t너무 매울 수 있으니 쿨피스 챙기세요!\n";
            Sleep(3000);
            system("spicy_bench_x86.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 0) {
            cls();
            check = 1;
            menu();
            break;
        }
        else {
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
        }
    }
}

void a64bit_menu()
{
    //윈도우 비트 확인
    if (sizeof(pInt) == 4)
    {
        a32bit_user_select_64bit();
        a32bit_menu();
    }
    //윈도우 비트 확인 끝
    cls();
    cout << "\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t 원하는 항목을 선택하세요! (64비트용)\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t 1. 순한맛 버전 실행\n";
    cout << "\t\t\t\t\t 2. 보통맛 버전 실행\n";
    cout << "\t\t\t\t\t 3. 매운맛 버전 실행\n";
    cout << "\t\t\t\t\t 0. 메인 메뉴로 돌아가기\n";
    cout << "\t\t\t--------------------------------------------------------------------\n";
    cout << "\n\n\t\t\t 메뉴를 선택하세요 : ";

    while (1)
    {
        int menu_num;
        cin >> menu_num;
        if (menu_num == 1) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t잠시 뒤 순한맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t진라면은 순한맛보단 매운맛이 더 맛이ㅆ...\n";
            Sleep(3000);
            system("mild_bench_x64.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 2) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t잠시 뒤 보통맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t예상보다 더 매울수 있다는 점, 참고하세요!\n";
            Sleep(3000);
            system("normal_bench_x64.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 3) {
            //화면을 지웁니다.
            cls();
            cout << "\n\t\t\t\t 뒤 매운맛 버전의 벤치마크가 실행됩니다.\n\t\t\t\t너무 매울 수 있으니 쿨피스 챙기세요!\n";
            Sleep(3000);
            system("spicy_bench_x64.exe");
            //프로그램을 종료합니다.
            exit(0);
        }
        else if (menu_num == 0) {
            cls();
            check = 1;
            menu();
            break;
        }
        else {
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
        }
    }
}

void exit_countdown()
{
    //화면을 지웁니다.
    cls();
    //안내 메시지를 출력합니다.
    cout << "\n\t\t\t\t\t\t5초 뒤 종료됩니다.\n";
    //1초(1000ms)간 대기합니다.
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t4초 뒤 종료됩니다.\n";
    //1초(1000ms)간 대기합니다.
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t3초 뒤 종료됩니다.\n";
    //1초(1000ms)간 대기합니다.
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t2초 뒤 종료됩니다.\n";
    //1초(1000ms)간 대기합니다.
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t1초 뒤 종료됩니다.\n";
    //1초(1000ms)간 대기합니다.
    Sleep(1000);
    cls();
    cout << "\n\t\t\t\t\t\t종료!\n";
    //프로그램을 종료합니다.
    exit(0);
}

void a32bit_user_select_64bit()
{
    MessageBox(NULL, L"현재 32비트를 사용하고 있습니다.\n64비트 프로그램은 동작하지 않습니다.\n따라서 32비트 전용 프로그램 선택 화면으로 이동합니다.", L"확인해 주세요!", MB_OK | MB_ICONWARNING);
}

void a64bit_user_select_32bit()
{
    MessageBox(NULL, L"현재 64비트를 사용하고 있습니다.\n성능 측정에 제한이 있을 수 있습니다.\n램 용량이 많으면 일부 파트에서 오류가 발생하는 문제가 있습니다.\n따라서 64비트 전용 프로그램 선택 화면으로 이동합니다.", L"확인해 주세요!", MB_OK | MB_ICONWARNING);
}