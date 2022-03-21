# 벤치마크 프로그램

C++로 만든 벤치마크 프로그램입니다. 여러가지 연산과 작업에 걸리는 시간을 측정해 성능이 얼마나 되는지 확인해 볼 수 있습니다.


# 진행되는 연산/작업

프로그램이 수행하는 연산/작업은 다음과 같습니다.

1. (연산) 1부터 600억까지 더하기
2. (연산) 원주율(π) 구하기
3. (작업) 다운로드 속도 측정
4. (작업) 영상 인코딩
5. (작업) waifu2x-converter-cpp로 업스케일링
6. (작업) 압축/압축해제

이후 기능들은 추가/변경/삭제 될 수 있습니다.

자세한 설명은 아래의 문단을 확인하세요.

## (연산) 1부터 600억까지 더하기

1부터 600억까지 더하는 연산을 수행합니다. 1+2+3+4+···+600억 이런식으로 연산을 시킵니다.
해당 부분의 코드는 다음과 같습니다.
```c++
    long long i = 0;
    long long sums = 0;
    for (i = 1; i <= 60000000000; i++) { //1부터 60000000000까지 반복
        sums += i; //sums=sums+i
    }
```
여기서 변수 <code>i</code>와 <code>sums</code>의 자료형은 <code>int</code>가 아닌 <code>long long</code>을 사용했는데, 그 이유는 <code>int</code>가 표시할 수 있는 범위는  <code>**-2,147,483,647 ~ +2,147,483,647**</code>까지이기에 30억은 <code>int</code>가 표시할 수 있는 범위인 약 21억을 초과하기에 <code>long long</code>을 사용한 것입니다. 참고로 <code>long long</code>이 표시할 수 있는 범위는 <code>**-9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,808**</code>입니다.

> 600억이라는 숫자는 변경될 가능성이 있습니다.

## (연산) 원주율(π) 구하기

오일러의 곱셈 공식으로 원주율을 계산합니다. 1부터 무한대까지 제곱한 뒤 역수로 만들어 각각 곱한 뒤, 6을 곱하고, 그 값에 루트를 씌우면 파이가 나옵니다. 이걸 식으로 나타내면 다음과 같습니다.

> ![image](https://user-images.githubusercontent.com/34927797/158953738-7700d5d6-8971-48e0-9e38-2d9494cb79ba.png)

이걸 N번 반복하면 원주율을 구할 수 있는데, 본 프로그램이 설정한 N의 값은 현재 <code>1000000000</code>입니다.

해당 코드는 다음과 같습니다.

```c++
    double pi=0.0,num=1.0;

    while(num<1000000000) {
        pi+=1.0/pow(num,2.0);
        num+=1.0;
    }
```

## (작업) 파일 다운로드

파일을 다운로드받는데 얼마나 걸리는지 시간을 측정합니다. 네트워크 상황에 따라 걸리는 시간이 다를 수 있습니다.
해외 서버에서 파일을 다운로드하는 경우, 통신사, 시간대에 따라 다르기 때문에 국내 서버에서 파일을 다운로드 받는 것으로 하였습니다. 해당 코드는 다음과 같습니다.

```c++
URLDownloadToFile(NULL, L"https://sel-kor-ping.vultr.com/vultr.com.1000MB.bin", L"./testfile.bin", 0, NULL);
```

vultr사의 속도 테스트 페이지에서 국내(서울 서버)에서 파일을 다운로드 받습니다. 해당 파일의 용량은 1000MB입니다.

## (작업) waifu2x-converter-cpp로 업스케일링

waifu2x-converter-cpp을 이용하여 작은 크기의 이미지를 40배 업스케일링합니다. 원본 이미지의 정보는 다음과 같습니다.

> * 파일 형식 : PNG
> * 크기 : 300 x 168(px)

업스케일링된 이미지의 정보는 다음과 같습니다.

> * 파일 형식 : PNG
> * 크기 : 12000 x 6720(px)

## (작업) waifu2x-converter-cpp로 업스케일링

waifu2x-converter-cpp을 이용하여 작은 크기의 이미지를 40배 업스케일링합니다. 원본 이미지의 정보는 다음과 같습니다.

> * 파일 형식 : PNG
> * 크기 : 300 x 168(px)

업스케일링된 이미지의 정보는 다음과 같습니다.

> * 파일 형식 : PNG
> * 크기 : 12000 x 6720(px)

## (작업) 압축/압축해제

7z.exe를 사용하여 파일을 압축/압축해제합니다.

압축될 폴더 정보는 다음과 같습니다.

> * 파일 갯수 : 100개
> * 크기 : 100MB x 50개, 500MB x 50개, 총 30,000MB(약 29.2GB)

압축할 포맷의 정보입니다.

> 1. 7z - 압축률 최대, 모든 스레드 사용
> 2. zip - 압축률 최대, 모든 스레드 사용