/* 
  파일이름: main.c
  작 성 자:60232361 류형찬
  하 는 일: RPG 형식의 캐릭터 생성 및 보스 잡기 게임 1.0
*/
#include <stdio.h>

int main(){
  char name;
  int job;// 직업(추후 번호가 아니라 직업이름으로 표시할 예정입니다)
  int hp; //체력
  double ad; //물리 공격력
  double ap; //마법 공격력
  //int faith; 신앙심(성직자의 회복스텟)(추후 추가예정입니다)
  double power;// 종합 전투력
  //첫번째 보스 체력 및 공격력
  int b1_hp;
  int b1_ad; 
  b1_hp=120;
  b1_ad=15;
  printf("보스 잡기 게임에 오신 걸 환영합니다!\n");
  printf("===============================\n");
  printf("캐릭터의 이름을 입력해주세요:");
  scanf(" %c", &name);
  printf("원하는 직업을 선택해주세요:1.전사,2.마법사,3.성직자:");
  scanf("%d", &job);
  printf("스텟 입력창입니다\n");
  printf("체력:");
  scanf("%d", &hp);
  printf("공격력:");
  scanf("%lf", &ad);
  printf("마력:");
  scanf("%lf", &ap);
  
  power = hp + ad + ap; //총 전투력 계산식

  printf("현재 캐릭터의 스텟 상황입니다\n");
  printf("이름:%c\n",name);
  printf("직업(1.전사,2.마법사,3.성직자):%d\n",job);
  printf("공격력:%.2f\n",ad);
  printf("마력:%.2f\n",ap);
  printf("총 전투력:%.2lf\n",power);
  
  printf("==============================\n");
  printf("첫번째 보스등장!\n");
  printf("보스의 체력:%d\n",b1_hp);
  printf("보스의 공격력:%d\n",b1_ad);
  printf("전투는 차후 구현됩니다. 업데이트를 기다려주세요");
  
  return 0;
}
