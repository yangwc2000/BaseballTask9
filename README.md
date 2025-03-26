BaseballTask9

1. 소개
- 3자리 숫자로 진행되는 숫자 야구(Bulls & Cows) 게임입니다.
- 언리얼 엔진 프로젝트로, C++ 라이브러리를 사용해 핵심 로직(난수 생성, 스트라이크/볼/아웃 판정)을 분리하였습니다.

4. 기능
- 3자리 랜덤 숫자 생성
  - 중복 없는 1~9 범위의 숫자 3개를 섞어서 생성합니다.
    - UGameHelper::GenerateRandomNumber() 사용.
  -스트라이크/볼/아웃 판정
    -플레이어 입력(Guess)과 정답(Answer)을 비교하여,
      -3 스트라이크면 ‘정답’
      -일부 맞으면 스트라이크/볼
      -전혀 없으면 아웃
    -UGameHelper::CheckGuess() 사용.
  -네트워크 연동
    -플레이어가 입력 → BBPlayerController 통해 서버에 전송 → BBGameState가 판정
    -서버가 브로드캐스트 → 모든 클라이언트 UI에 결과 표시
    -최대 3번 안에 맞추지 못하면 무승부 처리, 즉시 재시작.
  -UI
    -클라이언트 전용 위젯(UInGameWidget)이 있고, ListView를 이용해 매 입력 결과를 실시간 표시합니다.

5. 빌드 & 실행 방법
  -언리얼 엔진 5 프로젝트를 생성하고, 본 소스를 프로젝트 안에 넣습니다.
  -언리얼 에디터에서 .uproject 파일을 더블클릭해 프로젝트를 엽니다.
  -C++ 빌드를 진행합니다. (Visual Studio / Rider 등)
  -에디터 실행 후, Play 버튼을 눌러서 호스트/게스트 플레이어를 띄워보세요.
  -채팅창 또는 입력칸을 만들어서 "/123" 같은 형태로 숫자를 입력해보면 됩니다.

6. 추가 안내
  -중복 숫자 / 0 포함 입력 시 아웃 처리됩니다.
  -서버에서 JudgeResult() 내부 로직을 통해 승리/무승부 시 즉시 새 게임을 시작합니다.
