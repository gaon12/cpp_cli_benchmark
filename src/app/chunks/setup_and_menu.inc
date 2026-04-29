void level_explanation()
{
    cout << "-------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t다양한 매운맛을 선택하실 수 있습니다.\n\n";
    cout << "\t\t\t\t1. 순한맛(저사양 PC 사용 권장)\n";
    cout << "\t\t\t\t(진라면 순한맛은 좀...)\n\n";
    cout << "\t\t\t\t2. 보통맛(최소 i7 8700k 이상, 라이젠 5900x 이상 권장)\n";
    cout << "\t\t\t\t(보보 보통맛! 궁금해 허니!)\n\n";
    cout << "\t\t\t\t3. 매운맛(개발자는 5900x 사용중인데, 엄청 오래 걸림)\n";
    cout << "\t\t\t\t(모니터 불좀 꺼줄래? 내 벤치마크 좀 보게)\n\n";
    cout << "\t\t\t\t왠만해서는 매운맛 선택은 비추드립니다.\n";
    cout << "\t\t\t\t최고사양이더라도 보통맛을 권장드립니다.\n";
    cout << "\t\t\t\t개발자는 본 프로그램으로 인한 PC 고장에 책임을 지지 않습니다.\n";
    cout << "-------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t원하는 매운맛 정도를 입력하세요 : ";
}

int choose_level()
{
    system("title 벤치마크 - 매운맛 정도(난이도)를 선택하세요!");

    //무한 반복합니다.
    while (1)
    {
        cls();

        //설명 출력
        level_explanation();

        //사용자에게 메뉴값을 입력받고, 그 값을 scoville 변수에 저장합니다.
        scoville = read_menu_choice();

        //만약 1번을 입력하면
        if (scoville == 1)
        {
            //화면을 지웁니다.
            cls();
            //공통 준비파일 다운로드
            common_pre_download();
            //순한맛 실행
            mild();
            return scoville = 1;
            //while문을 나갑니다.
            break;
        }
        else if (scoville == 2)
        {
            //화면을 지웁니다.
            cls();
            //공통 준비파일 다운로드
            common_pre_download();
            //보통맛 실행
            normal();
            return scoville = 2;
            //while문을 나갑니다.
            break;
        }
        else if (scoville == 3)
        {
            //화면을 지웁니다.
            cls();
            //공통 준비파일 다운로드
            common_pre_download();
            //매운맛 실행
            spicy();
            return scoville = 3;
            //while문을 나갑니다.
            break;
        }
        else
        {
            cout << "잘못된 값을 입력하셨습니다. 다시 입력해 주시기 바랍니다.\n";
            Sleep(3000);
        }
    }
}

void introduction()
{
    //스플래시 화면
    splash();

    //인터넷 연결 여부 확인
    check_internet();

    //업데이트 확인
    update_check();

    system("title 벤치마크 - 약관 동의"); //콘솔창 제목 설정

    //약관 다운로드
    terms_download();

    //약관 동의 여부 확인
    terms_agree();

    //기존 파일들 삭제
    rm_usefiles();
    cls();
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

    cout << "\t\t\t\t  벤치마크 프로그램에 오신것을 환영합니다!\n";
    cout << "\t\t\t\t  인터넷 연결 여부를 확인하고 있습니다.\n";
    cout << "\t\t\t\t\t  잠시만 기다려 주세요!\n";
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

        //인터넷에 연결이 되어 있는 경우
        if (strstr(buffer, "TTL=") != NULL) {
            //인터넷 연결 오류 메시지를 출력합니다.
            cout << "\n\t\t\t 인터넷에 연결되어 있습니다. 방화벽에도 막혀있지 않습니다.\n\t\t\t\t 정상적으로 프로그램을 사용할 수 있습니다.\n";
            //3초(3000ms)간 대기합니다.
            Sleep(3000);
            cls();
        }
        //인터넷에 연결이 안되어 있는 경우
        else {
            //인터넷 연결 오류 메시지를 출력합니다.
            cout << "\n\t\t\t 인터넷에 연결되어 있지 않거나 방화벽에 차단되어 있습니다.\n\t\t\t\t 정상적인 프로그램 사용을 위해 인터넷을 연결하거나 방화벽에서 본 프로그램을 차단 해제해 주세요!\n 10초 뒤 프로그램이 자동 종료됩니다.";
            //10초(10000ms)간 대기합니다.
            Sleep(10000);
            exit(0);
        }
        //printf( "%d bytes read\n\n%s\n", rd, buffer );
        _pclose(pipe);
    }
    //명령어 실행에 실패한 경우
    else
    {
        cout << "Error in pipe opening!\n";
        cls();
        exit(0);
    }
}

void update_check()
{
    system("title 벤치마크 - 업데이트 확인 중..."); //콘솔창 제목 설정

    //최신 버전 정보가 담긴 파일을 다운로드합니다.
    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/latest_version_info.txt", L"latest_version_info.txt", "latest_version_info.txt");

    char latest[50];    // 파일을 읽을 때 사용할 임시 공간

    FILE* fp = fopen("latest_version_info.txt", "r");    // latest_version_info.txt 파일을 읽기 모드로 열기.
    if (fp == NULL || fgets(latest, sizeof(latest), fp) == NULL) {
        cerr << "\n[ERROR] 최신 버전 정보를 읽을 수 없습니다.\n";
        if (fp != NULL) fclose(fp);
        Sleep(3000);
        exit(1);
    }
    latest[strcspn(latest, "\r\n")] = '\0';

    //이 줄 위로는 latest_version_info.txt 파일 열기
    char current[50] = "1.0.1";


    //그 외인 경우(최신 버전과 현재 버전의 값이 다른 경우)
    if (strcmp(current, latest) != 0)
    {
        system("title 벤치마크 - 구버전을 사용하고 계십니다! 업데이트를 진행합니다!"); //콘솔창 제목 설정

        //안내 메시지 출력
        cout << "\n\t\t\t\t현재(" << current << ") 최신버전(" << latest << ")을 사용하고 계시지 않습니다.\n\t\t\t\t\t\t업데이트를 시작합니다.";
        //3초(3000ms)간 대기
        Sleep(3000);

        //업데이트 프로그램을 다운로드합니다.
        download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/updater.exe", L"updater.exe", "updater.exe");
        //업데이트 프로그램을 실행합니다.
        system("updater.exe");
        //프로그램 종료(업데이트 프로그램이 벤치마크 프로그램을 시작시킴)
        exit(0);
    }
    //최신 버전과 현재 버전이 일치하는 경우
    else
    {
        system("title 벤치마크 - 최신버전을 사용하고 계십니다!"); //콘솔창 제목 설정

        //안내 메시지 출력
        cout << "\n\t\t\t\t현재(" << current << ") 최신버전(" << latest << ")을 사용하고 계십니다.\n\t\t\t\t\t\t잠시 후 계속됩니다.";
        //3초(3000ms)간 대기
        Sleep(3000);
        //화면 초기화
        cls();
    }
    //열었던 파일을 닫습니다.
    fclose(fp); //최신 버전 정보가 담긴 파일을 닫습니다.
}

void terms_download()
{
    /*
    약관 동의 페이지
    프로그램이 멈추거나, 심하면 OS가 작동 중지 될 수도(사양이 낮을 경우) 있기 때문에, 약관에 동의하는 것을 추가합니다.
    약관 내용은 txt 파일을 불러오는 것으로 하였습니다.
    */
    //약관 파일을 다운로드 합니다.
    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/terms.txt", L"terms.txt", "terms.txt"); //약관 파일을 다운로드합니다.
}

void terms_agree()
{
    cout << "---------------------------------------------------------------------------------------------\n";
    //약관 파일을 엽니다.
    char buffer[10000];    // 파일을 읽을 때 사용할 임시 공간
    FILE* fp = fopen("terms.txt", "r");    // terms.txt 파일을 읽기 모드로 열기.  
                                           // 파일 포인터를 반환
    while (1)
    {
        fgets(buffer, sizeof(buffer), fp);    // terms.txt에서 문자열을 읽음
        printf("%s\n", buffer);    // 파일의 내용 출력
        if (feof(fp)) break;
    }

    fclose(fp);    // 파일 포인터 닫기
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "\n\n 약관에 동의하십니까? 동의하시면 \"1\"을, 프로그램이 수집하는 내용을 확인하려면 \"2\"를, 종료는 \"0\"를 입력해 주세요 : ";

    /*
    while문을 사용한 이유는 다음과 같습니다.
    if문만 사용할 경우, 메뉴에 없는 값을 입력할 경우 되돌아가려면 goto문을 사용해야 합니다.
    하지만 while문과 같이 사용하는 경우에는 메뉴에 없는 값을 입력하면 계속 반복시킬수 있고,
    메뉴에 있는 값을 입력하면 break 처리하면 되기 때문에 더욱 편리합니다.
    */

    //무한 반복합니다.
    while (1)
    {
        //메뉴를 입력받을 때 저장할 변수를 선언합니다.
        int terms_agree;

        //사용자에게 메뉴값을 입력받고, 그 값을 terms_agree 메모리에 저장합니다.
        terms_agree = read_menu_choice();

        //만약 1번을 입력하면
        if (terms_agree == 1) {
            //화면을 지웁니다.
            cls();
            //while문을 나갑니다.
            break;
        }

        //만약 2번을 입력하면
        else if (terms_agree == 2) {
            help_document();
            if (check == 1)
                break;
        }
        else if (terms_agree == 0) {
            cls();
            exit_countdown();
        }
        else {
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
            cls();
        }
    }
}

void help_document() {
    system("title 벤치마크 - 도움말"); //콘솔창 제목 설정

    cls();

    cout << "-------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t * 본 프로그램이 저장하는 값은 다음과 같습니다.\n\n";
    cout << "\t\t1. 각 파트별 소요 시간값\n";
    cout << "\t\t2. 벤치마크이 완료될 때의 날짜와 시간값\n";
    cout << "\t\t3. PC 정보 일부(CPU 이름, 스레드 수, RAM 용량, GPU 이름)\n\n";
    cout << "\t\t * 결과 페이지에서 수집하는 정보는 다음과 같습니다.\n";
    cout << "\t\t   - 브라우저 유저 에이전트 값\n\n";
    cout << "\t\t * 인터넷에 연결되어 있어야 하는 이유와 다운로드하는 파일은 다음과 같습니다.\n";
    cout << "\t\t1. 약관 파일(약관 동의해야 진행 가능)\n";
    cout << "\t\t2. 각 파트별 필요 프로그램\n";
    cout << "\t\t(waifu2x - converter, 7zip, John the Ripper, Vultr 파일 다운로드 속도 테스트용 파일)\n";
    cout << "\t\t3. 결과 페이지(디자인 프레임워크로 UIKit, UIKit-Icon 사용)\n";
    cout << "-------------------------------------------------------------------------------------------------------------------\n";
    cout << "\n\n 확인하였고, 계속 진행하려면 \"1\"을, 이전 화면(약관 확인)으로 이동하려면 \"2\"를, 종료는 \"0\"을 입력해 주세요 : ";

    while (1)
    {
        int helpdoc_agree;
        helpdoc_agree = read_menu_choice();
        if (helpdoc_agree == 1) {
            cls();
            check = 1;
            break;
        }
        else if (helpdoc_agree == 2) {
            cls();
            check = 1;
            terms_agree();
            break;
        }
        else if (helpdoc_agree == 0) {
            cls();
            exit_countdown();
        }
        else {
            cout << "\n\nㅁ ERROR! 잘못 입력하셨습니다. 다시 입력해 주시기 바랍니다!";
        }
    }
}

void mild_pre_download()
{
    system("title 벤치마크 - 필요한 파일들 다운로드 중..."); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n\t\t\t\t  벤치마크 프로그램입니다.\n\t\t\t  필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n";

    /*
    필요한 파일들을 다운로드받습니다.
    파일 목록과 사유는 다음과 같습니다.
    * mildall.7z : 벤치마크에 필요한 파일들이 모여있습니다.
    */

    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/mildalls.7z", L"mildalls.7z", "mildalls.7z"); //waifu2x, 테스트용 압축 파일이 담긴 압축파일을 다운로드합니다.
    system("@echo off && 7z x mildalls.7z > 1.txt"); //다운로드 받은 파일을 압축해제합니다.
    cls();
}

void common_pre_download()
{
    //난이도와 상관 없이 공통으로 필요한 파일은 해당 함수에서 다운로드합니다.
    /*
    필요한 파일들을 다운로드받습니다.
    파일 목록과 사유는 다음과 같습니다.
    * 7z.exe, 7z.dll : 각종 파일들을 모아둔 all.7z 파일을 압축해제하고, 이후에 파일 압축/압축 해제시 사용되는 파일입니다.
    * aki.png : 업스케일링 대상 파일입니다.
    * index.html : 최종 결과 출력용 html 파일입니다.
    */
    download_file_or_exit(L"https://common.gaon.xyz/utils/x64/7-Zip/7z.exe", L"7z.exe", "7z.exe"); //7z.exe를 다운로드합니다.
    download_file_or_exit(L"https://common.gaon.xyz/utils/x64/7-Zip/7z.dll", L"7z.dll", "7z.dll"); //7z.exe이 동작하는데 필요한 파일인 7z.dll 파일을 다운로드합니다.
    download_file_or_exit(L"https://i.ibb.co/1b2Ns1b/aki.png", L"aki.png", "aki.png");//크기가 작은 이미지 파일을 다운로드합니다.
    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/result/index.html", L"index.html", "index.html");//최종 결과 화면을 띄울 html 파일을 다운로드합니다.
}

void pre_download()
{
    system("title 벤치마크 - 필요한 파일들 다운로드 중..."); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n\t\t\t\t  벤치마크 프로그램입니다.\n\t\t\t  필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n";

    /*
    필요한 파일들을 다운로드받습니다.
    파일 목록과 사유는 다음과 같습니다.
    * all.7z : 벤치마크에 필요한 파일들이 모여있습니다.
    */

    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/all.7z", L"all.7z", "all.7z"); //waifu2x, 테스트용 압축 파일이 담긴 압축파일을 다운로드합니다.
    system("@echo off && 7z x all.7z > 1.txt"); //다운로드 받은 파일을 압축해제합니다.
    cls();
}

void spicy_pre_download()
{
    system("title 벤치마크 - 필요한 파일들 다운로드 중..."); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n\t\t\t\t  벤치마크 프로그램입니다.\n\t\t\t  필요한 파일들을 다운로드하고 있습니다. 잠시만 기다려주세요.\n";

    /*
    필요한 파일들을 다운로드받습니다.
    파일 목록과 사유는 다음과 같습니다.
    * spicyall.7z : 벤치마크에 필요한 파일들이 모여있습니다.
    */

    download_file_or_exit(L"https://common.gaon.xyz/prj/cpp_cli_benchmark/spicyall.7z", L"spicyall.7z", "spicyall.7z"); //waifu2x, 테스트용 압축 파일이 담긴 압축파일을 다운로드합니다.
    system("@echo off && 7z x spicyall.7z > 1.txt"); //다운로드 받은 파일을 압축해제합니다.
    cls();
}

