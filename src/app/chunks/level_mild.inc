void mild() {
    //필요한 파일을 다운로드합니다.
    mild_pre_download();

    Sleep(600);
    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    Sleep(800);

    steady_clock::time_point StartTime = steady_clock::now();//시간 계산 시작

    //파트1 - 1부터 100억까지 더하기
    mild_adds();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : ";

    steady_clock::time_point FirstPartEndTime = steady_clock::now();
    duration<double> DefaultSec = FirstPartEndTime - StartTime;
    milliseconds mill = duration_cast<milliseconds>(FirstPartEndTime - StartTime);
    seconds sec = duration_cast<seconds>(FirstPartEndTime - StartTime);
    cout << mill.count() << "ms" << "(" << sec.count() << "초)";//시간 출력

    //파트2 - 원주율 구하기
    mild_pi_calc();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : ";

    steady_clock::time_point SecondPartEndTime = steady_clock::now();
    duration<double> DefaultSec_second = SecondPartEndTime - FirstPartEndTime;
    milliseconds mill_second = duration_cast<milliseconds>(SecondPartEndTime - FirstPartEndTime);
    seconds sec_second = duration_cast<seconds>(SecondPartEndTime - FirstPartEndTime);
    cout << mill_second.count() << "ms" << "(" << sec_second.count() << "초)";//시간 출력

    //파트3 - 업스케일링 10배
    mild_upscale();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력;
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : ";

    steady_clock::time_point ThirdPartEndTime = steady_clock::now();
    duration<double> DefaultSec_Third = ThirdPartEndTime - SecondPartEndTime;
    milliseconds mill_third = duration_cast<milliseconds>(ThirdPartEndTime - SecondPartEndTime);
    seconds sec_third = duration_cast<seconds>(ThirdPartEndTime - SecondPartEndTime);
    cout << mill_third.count() << "ms" << "(" << sec_third.count() << "초)";//시간 출력

    //파트4 - 압축/압축 해제
    compress();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력;
    cout << "4. 압축/압축 해제 작업 : ";

    steady_clock::time_point FourthPartEndTime = steady_clock::now();
    duration<double> DefaultSec_Fourth = FourthPartEndTime - ThirdPartEndTime;
    milliseconds mill_fourth = duration_cast<milliseconds>(FourthPartEndTime - ThirdPartEndTime);
    seconds sec_fourth = duration_cast<seconds>(FourthPartEndTime - ThirdPartEndTime);
    cout << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)";//시작 출력

    //파트5 - 무리수 e 구하기
    mild_e_calc();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력;
    cout << "4. 압축/압축 해제 작업 : " << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)\n";//시작 출력
    cout << "5. 무리수 e 구하기 : ";

    steady_clock::time_point FifthPartEndTime = steady_clock::now();
    duration<double> DefaultSec_Fifth = FifthPartEndTime - FourthPartEndTime;
    milliseconds mill_fifth = duration_cast<milliseconds>(FifthPartEndTime - FourthPartEndTime);
    seconds sec_fifth = duration_cast<seconds>(FifthPartEndTime - FourthPartEndTime);
    cout << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)";//시작 출력

    //파트6 - 암호걸린 압축파일 비밀번호 찾기
    decrypt_zip();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력;
    cout << "4. 압축/압축 해제 작업 : " << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)\n";//시작 출력
    cout << "5. 무리수 e 구하기 : " << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)\n";//시작 출력
    cout << "6. 압축파일 암호 풀기 : ";

    //파트6을 진행하면 진행 과정이 화면에 나오기 때문에, 완료되면 바로 화면을 지우고 기존 값으로 덮어씌웁니다.
    cls();

    steady_clock::time_point SixthPartEndTime = steady_clock::now();
    duration<double> DefaultSec_Sixth = SixthPartEndTime - FifthPartEndTime;
    milliseconds mill_sixth = duration_cast<milliseconds>(SixthPartEndTime - FifthPartEndTime);
    seconds sec_sixth = duration_cast<seconds>(SixthPartEndTime - FifthPartEndTime);

    //파트6을 진행하면 진행 과정이 화면에 나오기 때문에, 완료되면 바로 화면을 지우고 기존 값으로 덮어씌웁니다.
    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력;
    cout << "4. 압축/압축 해제 작업 : " << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)\n";//시작 출력
    cout << "5. 무리수 e 구하기 : " << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)\n";//시작 출력
    cout << "6. 압축파일 암호 풀기 : " << mill_sixth.count() << "ms" << "(" << sec_sixth.count() << "초)\n";//시작 출력

    //번외 테스트는 총 시간에 포함시키지 않기 위해 시점 조정
    steady_clock::time_point EndTime = steady_clock::now();

    //번외 테스트(다운로드 시간)
    steady_clock::time_point ExtraTestStartTime = steady_clock::now();//시간 계산 시작

    //번외 - 다운로드 속도 측정
    mild_download_test();

    cls();

    cout << "\n현재 수행중인 작업은 다음과 같습니다. (순한맛 버전)\n\n";
    cout << "1. 1부터 100억까지 더하기 : " << mill.count() << "ms" << "(" << sec.count() << "초)\n";//시간 출력
    cout << "2. 원주율 구하기 : " << mill_second.count() << "ms" << "(" << sec_second.count() << "초)\n";//시간 출력
    cout << "3. 머신러닝(SRCNN) 기반 이미지 업스케일링 작업(10배) : " << mill_third.count() << "ms" << "(" << sec_third.count() << "초)\n";//시간 출력;
    cout << "4. 압축/압축 해제 작업 : " << mill_fourth.count() << "ms" << "(" << sec_fourth.count() << "초)\n";//시작 출력
    cout << "5. 무리수 e 구하기 : " << mill_fifth.count() << "ms" << "(" << sec_fifth.count() << "초)\n";//시작 출력
    cout << "6. 압축파일 암호 풀기 : " << mill_sixth.count() << "ms" << "(" << sec_sixth.count() << "초)\n";//시작 출력
    cout << "번외 - 파일 다운로드 속도 측정 : ";

    steady_clock::time_point ExtraTestEndTime = steady_clock::now();
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

    string gpu_name_info(gpu_info);

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
    sprintf(minute, "%d", t->tm_min);
    sprintf(wday, "%d", t->tm_wday);


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

    FILE* fp = 0;
    fopen_s(&fp, "important_values.js", "w");    // important_values.js 파일을 쓰기 모드(w)로 열기.
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

    fputs(strcat(plus_time, ch_plus_time), fp);
    fputs(";\n", fp);
    fputs(strcat(pi_time, ch_pi_time), fp);
    fputs(";\n", fp);
    fputs(strcat(download_time, ch_download_time), fp);
    fputs(";\n", fp);
    fputs(strcat(upscale_time, ch_upscale_time), fp);
    fputs(";\n", fp);
    fputs(strcat(compress_time, ch_compress_time), fp);
    fputs(";\n", fp);
    fputs(strcat(surd_e_time, ch_surd_e_time), fp);
    fputs(";\n", fp);
    fputs(strcat(decrypt_zip_time, ch_decrypt_zip_time), fp);
    fputs(";\n", fp);

    //PC 정보 추가
    //CPU 이름 추가
    char cpu_name[70] = "var cpu_name = \"";
    fputs(strcat(cpu_name, CPUBrandString), fp);
    fputs("\";\n", fp);

    //RAM 크기 추가
    char ram_size[70] = "var ram_size = ";
    DWORD DTotalRamSize = dwTotalPhys / dwMBFactor / 1000;
    //DWORD를 char로 변환
    char TotalRamSize[10];
    sprintf(TotalRamSize, "%d", DTotalRamSize);
    fputs(strcat(ram_size, TotalRamSize), fp);
    fputs(";\n", fp);

    //GPU 이름 추가
    char gpu_name[70] = "var gpu_name = \"";
    fputs(strcat(gpu_name, gpu_name_raw), fp);
    fputs("\b\";\n", fp);

    //현재 날짜 추가
    char now_date_year[70] = "var now_date_year = \"";
    fputs(strcat(now_date_year, year), fp);
    fputs("\b\";\n", fp);

    char now_date_month[70] = "var now_date_month = \"";
    fputs(strcat(now_date_month, month), fp);
    fputs("\b\";\n", fp);

    char now_date_day[70] = "var now_date_day = \"";
    fputs(strcat(now_date_day, day), fp);
    fputs("\b\";\n", fp);

    char now_date_hours[70] = "var now_date_hours = \"";
    fputs(strcat(now_date_hours, hours), fp);
    fputs("\b\";\n", fp);

    char now_date_minute[70] = "var now_date_minute = \"";
    fputs(strcat(now_date_minute, minute), fp);
    fputs("\b\";\n", fp);

    char now_date_wday[70] = "var now_date_wday = \"";
    fputs(strcat(now_date_wday, wday), fp);
    fputs("\b\";\n", fp);

    //윈도우 비트 표시
    if (x64 == 1)
    {
        char windows_bits[70] = "var windows_bits = \"";
        char bits[20] = "64";
        fputs(strcat(windows_bits, bits), fp);
        fputs("\b\";\n", fp);
    }
    else if (x64 == 2)
    {
        char windows_bits[70] = "var windows_bits = \"";
        char bits[20] = "32";
        fputs(strcat(windows_bits, bits), fp);
        fputs("\b\";\n", fp);
    }
    fclose(fp);    // 파일 포인터 닫기
    write_result_json(
        mill.count(), mill_second.count(), mill_extra.count(), mill_third.count(), mill_fourth.count(), mill_fifth.count(), mill_sixth.count(),
        CPUBrandString, static_cast<unsigned long>(DTotalRamSize), gpu_name_raw,
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_wday,
        (x64 == 1 ? 64 : 32));
}

