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
  //첫번째 보스 체력 및 공격력
  int b1_hp;
  int b1_ad; 
  b1_hp=120;
  b1_ad=15;
  int try; //보스 입장 여부 확인 변수
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
      power= ad*1.2 + hp*15;
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
      faith=1.4*ad + 1.5*ap;
      printf("공격력 입력(1포인트당 1.4):");
      scanf("%lf",&ad);
      printf("마력 입력(1포인트당 1.5):");
      scanf("%lf",&ap);
      power = faith + hp;
      break;

  }
  


  printf("현재 캐릭터의 스텟 상황입니다\n");
  printf("이름:%c\n",name);
  printf("직업(1.전사,2.마법사,3.성직자):%d\n",job);
  printf("공격력:%.2f\n",ad);
  printf("마력:%.2f\n",ap);
  printf("총 전투력:%.2lf\n",power);
  printf("보스 레이드를 하시고 싶으시면 1,그렇지 않으면 0을 눌러주세요!");
  int boss_start;
  scanf("%d",&boss_start);
  if(boss_start==1)
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
  if(try==1)
  {
    printf("전투를 시작합니다!\n");
    elif(power>=b1_hp);
    {
      printf("축하합니다! 승리하셨습니다! 다음 스테이지로 넘어갑니다\n");
    }
    else
    {
      printf("패배하셨습니다..다시 시도해보세요\n");
    }
  }
  else
    {
      printf("메뉴화면으로 돌아갑니다");
    }
  return 0;

}
