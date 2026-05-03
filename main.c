/* 
  파일이름: main.c
  작 성 자:60232361 류형찬
  하 는 일: RPG 형식의 캐릭터 생성 및 보스 잡기 게임 1.0
*/
#include <stdio.h>

int main(){
  char name;
  int job;// 번호를 입력받아 직업 설정
  int hp; //체력
  double ad; //물리 공격력
  double ap; //마법 공격력
  double faith; //신앙심(성직자의 주요스텟)
  double power;// 종합 전투력
  int hunt_try;//사냥터 진행 횟수
  int i;
  //첫번째 보스 체력 및 공격력
  int b1_hp;
  int b1_ad; 
  b1_hp=120;
  b1_ad=15;
  int try; //보스 입장 여부 확인 변수
  int level=1;//직업 레벨
  int exp=0;//경험치량


  printf("보스 잡기 게임에 오신 걸 환영합니다!\n");
  printf("===============================\n");
  printf("캐릭터의 이름을 입력해주세요:");
  scanf(" %c", &name);
  printf("원하는 직업을 선택해주세요:1.전사,2.마법사,3.성직자:");
  scanf("%d", &job);
  switch(job){
    case 1:
      printf("전사를 고르셨습니다\n");
      printf("체력 입력(1포인트당15):");  
      scanf("%d",&hp);
      printf("공격력 입력(1포인트당 1.2):");
      scanf("%lf" , &ad);
      power= ad*1.3 + hp*15;
      break;

    case 2:
      printf("마법사를 고르셨습니다\n");
      printf("체력 입력(1포인트당 0.9):");  
      scanf("%d",&hp);
      printf("마력 입력(1포인트당 2.2):");
      scanf("%lf",&ap);
      power = ap*2.2 + hp*0.9;
      break;

    case 3:
      printf("성직자를 고르셨습니다\n");
      printf("체력 입력(1포인트당 1):");  
      scanf("%d",&hp);
      printf("공격력 입력(1포인트당 1.4):");
      scanf("%lf",&ad);
      printf("마력 입력(1포인트당 1.5):");
      scanf("%lf",&ap);
      faith=1.4*ad + 1.5*ap;
      power = faith + hp;
      break;

  }

  printf("현재 캐릭터의 스텟 상황입니다\n");
  printf("이름:%c\n",name);
  printf("직업(1.전사,2.마법사,3.성직자):%d\n",job);
  printf("현재 레벨:%d\n",level);
  printf("체력:%d\n",hp);
  printf("공격력:%.2f\n",ad);
  printf("마력:%.2f\n",ap);
  printf("총 전투력:%.2lf\n",power);
  printf("캐릭터 생성이 완료되었습니다!\n");
  printf("");
  printf("사냥터에 가시려면 1,보스 레이드는 2,메뉴로 가려면 0을 눌러주세요");
  int boss_start;
  scanf("%d",&boss_start);
  if(boss_start==1)
  {
    printf("사냥터에 오신 것을 환영합니다!");
    printf("사냥횟수를 입력하세요\n");
    scanf("%d", &hunt_try);
    for(i=1;i<=hunt_try;i++){
      int gain=25;//획득 경험치
      exp+=gain;
      printf("%d만큼의 경험치를 힉득하였습니다\n",gain);
      if(exp>=100){
        printf("레벨업 하였습니다\n");
        exp-=100;
        level+=1;
        switch(job){
          case 1:
            hp+=20;
            ad+=7;
            power= ad*1.3 + hp*15;
            break;
          case 2:
            hp+=10;
            ap+=5;
            power= ap*2.2 + hp*0.9;
            break;
          case 3:
            hp+=15;
            ad+=4;
            ap+=3;
            power=1.4*ad + 1.5*ap + hp;
            break;
        }
      }
    }
  }
  
  else if(boss_start==2)
  {
    printf("보스레이드를 시작합니다!\n");
  }
  else
  {
    printf("메뉴화면으로 돌아갑니다\n");
  }
  
  printf("==============================\n");
  printf("첫번째 보스등장!\n");
  printf("보스의 체력:%d\n",b1_hp);
  printf("보스의 공격력:%d\n",b1_ad);
  printf("도전하시겠습니까?");
  scanf("%d",&try);
  if(try== 1)
  {
    printf("전투를 시작합니다\n");
    if(power >= b1_hp){
      printf("승리! 다음보스로 넘어갑니다\n");
    }
    else{
      printf("패배...다시 도전해보세요\n");
    } 
  }
  return 0;
  

}
