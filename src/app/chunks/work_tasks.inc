void mild_adds()
{
    system("title 벤치마크 - (연산) 1부터 100억까지 더하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "1. 1부터 100억까지 더하기 : ";

    br(5);
    progress(10);


    //1부터 100억까지 더합니다.
    long long i = 0;
    long double sums = 0;
    for (i = 1; i <= 10000000000; i++) { //1부터 10000000000까지 반복
        sums += i; //sums=sums+i
    }
    g_bench_sink += sums;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void adds()
{
    system("title 벤치마크 - (연산) 1부터 300억까지 더하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "1. 1부터 300억까지 더하기 : ";

    br(5);
    progress(10);


    //1부터 300억까지 더합니다.
    long long i = 0;
    long double sums = 0;
    for (i = 1; i <= 30000000000; i++) { //1부터 30000000000까지 반복
        sums += i; //sums=sums+i
    }
    g_bench_sink += sums;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void spicy_adds()
{
    system("title 벤치마크 - (연산) 1부터 600억까지 더하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "1. 1부터 600억까지 더하기 : ";

    br(5);
    progress(10);

    //1부터 600억까지 더합니다.
    long long i = 0;
    long double sums = 0;
    for (i = 1; i <= 60000000000; i++) { //1부터 60000000000까지 반복
        sums += i; //sums=sums+i
    }
    g_bench_sink += sums;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void mild_pi_calc()
{
    system("title 벤치마크 - (연산) 원주율 구하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n2. 원주율 구하기 : ";

    br(5);
    progress(30);

    double pi = 0.0, num = 1.0;

    while (num < 400000000)
    {
        pi += 1.0 / (num * num);
        num += 1.0;
    }
    g_bench_sink += pi;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void pi_calc()
{
    system("title 벤치마크 - (연산) 원주율 구하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n2. 원주율 구하기 : ";

    br(5);
    progress(30);

    double pi = 0.0, num = 1.0;

    while (num < 1000000000)
    {
        pi += 1.0 / (num * num);
        num += 1.0;
    }
    g_bench_sink += pi;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void spicy_pi_calc()
{
    system("title 벤치마크 - (연산) 원주율 구하기"); //콘솔창 제목 설정

    //안내 메시지를 출력합니다.
    cout << "\n2. 원주율 구하기 : ";

    br(5);
    progress(30);

    double pi = 0.0, num = 1.0;

    while (num < 2147483640)
    {
        pi += 1.0 / (num * num);
        num += 1.0;
    }
    g_bench_sink += pi;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void mild_upscale()
{
    system("title 벤치마크 - (작업) waifu2x 10배 업스케일링 작업"); //콘솔창 제목 설정
    cout << "\n3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : ";

    br(5);
    progress(55);

    system("@echo off && waifu2x-converter-cpp  --scale-ratio 10 -i aki.png -o aki_out.png > 1.txt");
}

void upscale()
{
    system("title 벤치마크 - (작업) waifu2x 30배 업스케일링 작업"); //콘솔창 제목 설정
    cout << "\n3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(30배) : ";

    br(5);
    progress(55);

    system("@echo off && waifu2x-converter-cpp  --scale-ratio 30 -i aki.png -o aki_out.png > 1.txt");
}

void spicy_upscale()
{
    system("title 벤치마크 - (작업) waifu2x 60배 업스케일링 작업"); //콘솔창 제목 설정
    cout << "\n3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(60배) : ";

    br(5);
    progress(55);

    system("@echo off && waifu2x-converter-cpp  --scale-ratio 60 -i aki.png -o aki_out.png > 1.txt");
}

void compress()
{
    system("title 벤치마크 - (작업) 압축/압축 해제 작업"); //콘솔창 제목 설정
    cout << "\n4. 압축/압축 해제 작업 : ";

    br(5);
    progress(70);

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

void mild_e_calc()
{
    system("title 벤치마크 - (연산) 무리수 e 구하기"); //콘솔창 제목 설정
    cout << "\n5. 무리수 e 구하기 : ";

    br(5);
    progress(85);

    int ntimes = 56000;
    int add;
    double j, surd_e;
    surd_e = 1;

    for (add = 1; add <= ntimes; add++)
    {
        j = 1 / factorial(add);
        surd_e = surd_e + j;
    }
    g_bench_sink += surd_e;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void e_calc()
{
    system("title 벤치마크 - (연산) 무리수 e 구하기"); //콘솔창 제목 설정
    cout << "\n5. 무리수 e 구하기 : ";

    br(5);
    progress(85);

    int ntimes = 130000;
    int add;
    double j, surd_e;
    surd_e = 1;

    for (add = 1; add <= ntimes; add++)
    {
        j = 1 / factorial(add);
        surd_e = surd_e + j;
    }
    g_bench_sink += surd_e;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void spicy_e_calc()
{
    system("title 벤치마크 - (연산) 무리수 e 구하기"); //콘솔창 제목 설정
    cout << "\n5. 무리수 e 구하기 : ";

    br(5);
    progress(85);

    int ntimes = 270000;
    int add;
    double j, surd_e;
    surd_e = 1;

    for (add = 1; add <= ntimes; add++)
    {
        j = 1 / factorial(add);
        surd_e = surd_e + j;
    }
    g_bench_sink += surd_e;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

void decrypt_zip() {
    system("title 벤치마크 - (작업) 압축파일 암호 풀기"); //콘솔창 제목 설정
    cout << "\n6. 압축파일 암호 풀기 : ";

    br(5);
    progress(90);

    system("@echo off && cd john && zip2john test.zip > hash.txt && john hash.txt > 1.txt");
}

void mild_download_test()
{
    system("title 벤치마크 - (작업) 파일 다운로드 속도 측정"); //콘솔창 제목 설정
    cout << "\n번외 - 파일 다운로드 속도 측정 : ";

    br(5);
    progress(98);

    download_file_or_exit(L"https://dl.google.com/android/repository/commandlinetools-win-8512546_latest.zip", L"cmdtools.zip", "cmdtools.zip");
}

void download_test()
{
    system("title 벤치마크 - (작업) 파일 다운로드 속도 측정"); //콘솔창 제목 설정
    cout << "\n번외 - 파일 다운로드 속도 측정 : ";

    br(5);
    progress(98);

    download_file_or_exit(L"https://redirector.gvt1.com/edgedl/android/studio/install/2021.2.1.14/android-studio-2021.2.1.14-windows.exe", L"android_studio.exe", "android_studio.exe");
}

void spicy_download_test()
{
    system("title 벤치마크 - (작업) 파일 다운로드 속도 측정"); //콘솔창 제목 설정
    cout << "\n번외 - 파일 다운로드 속도 측정 : ";

    br(5);
    progress(98);

    download_file_or_exit(L"https://dl.google.com/android/studio/maven-google-com/stable/offline-gmaven-stable.zip", L"gmaven.zip", "gmaven.zip");
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


