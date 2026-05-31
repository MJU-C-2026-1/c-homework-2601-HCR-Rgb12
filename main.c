/* 
  파일이름: main.c
  작 성 자:60232361 류형찬
  하 는 일: RPG 형식의 캐릭터 생성 및 보스 잡기 게임 3.0
*/

#include <stdio.h>
//함수 파트
//메인메뉴의 함수화
void print_menu()
{
  printf("C언어RPG 게임에 오신 걸 환영합니다!\n"); 
  printf("===============================\n");
  printf("메뉴를 선택해주세요\n");
  printf("1.캐릭터 생성\n");
  printf("2.사냥터 입장\n");
  printf("3.보스 레이드\n");
  printf("0.게임 종료\n");
} 

//전투력 계산 함수
double output_power(int job,int hp, double ad, double ap)
{
  double faith; //신앙심(성직자의 주요스텟)
  double power;// 총 전투력
  switch(job)
  {
    case(1):
      power= ad*1.3 + hp*1.5; //전사
      break;
    case(2):
      power = ap*2.2 + hp*0.9;//마법사
      break;
    case(3):
      faith = 1.4*ad + 1.5*ap;//성직자
      power = faith + hp;
      break;
  }
  return power;
}
// 현재 스텟 출력 함수
void status(char name, int job,int level, int hp, double ad,double ap,double power)
{
  printf("==========================\n");
  printf("현재 스텟 상황입니다\n");
  printf("이름: %c\n" , name);
  printf("현재 레벨: %d\n",level);
  printf("체력:%d\n",hp);
  printf("공격력:%.2f\n",ad);
  printf("마력:%.2f\n",ap);
  printf("총 전투력:%.2lf\n",power);
  printf("==========================\n");
}
//전역변수-보스 전투때 사용
int boss_level = 1;
double boss_hp = 850;
double boss_power = 800;

int main(){
  char name;
  int menu;//메뉴화면 입장변수
  int job;// 번호를 입력받아 직업 설정
  int hp; //체력
  double ad; //물리 공격력
  double ap; //마법 공격력
  double faith; //신앙심(성직자의 주요스텟)
  double power;// 총 전투력
  int hunt_try;//사냥터 진행 횟수
  int i; //반복문 변수
  int next; //보스 입장 여부 확인 변수
  int level=1;//직업 레벨
  int exp=0;//경험치량

  while(1)
  {
    print_menu();
    scanf("%d",&menu);
    if(menu == 0)
    {
      printf("게임을 종료합니다");
      break;
    }
    
    switch(menu)
    {
      case(1):
      {
        printf("캐릭터의 이름을 입력해주세요:");
        scanf(" %c", &name);
        printf("원하는 직업을 선택해주세요:1.전사,2.마법사,3.성직자:");
        scanf("%d", &job);
        switch(job)
        {
          case 1:
            printf("전사를 고르셨습니다\n");
            printf("체력 입력(1포인트당1.5):");  
            scanf("%d",&hp);
            printf("공격력 입력(1포인트당 1.3):");
            scanf("%lf" , &ad);
            break;

          case 2:
            printf("마법사를 고르셨습니다\n");
            printf("체력 입력(1포인트당 0.9):");  
            scanf("%d",&hp);
            printf("마력 입력(1포인트당 2.2):");
            scanf("%lf",&ap);
            break;

          case 3:
            printf("성직자를 고르셨습니다\n");
            printf("체력 입력(1포인트당 1.2):");  
            scanf("%d",&hp);
            printf("공격력 입력(1포인트당 1.2):");
            scanf("%lf",&ad);
            printf("마력 입력(1포인트당 1.4):");
            scanf("%lf",&ap);
            break;
        }//직업 선택 및 스텟 설정 끝
        power = output_power(job, hp, ad, ap);//함수 호출
        status(name, job, level, hp, ad, ap, power);          
        break;
      } 
      case(2):{
        printf("사냥터에 오신 것을 환영합니다!\n");//사냥터를 통한 경험치 획득 및 레벨업 수식
        printf("사냥횟수를 입력하세요:");
        scanf("%d", &hunt_try);
        int total_gain = hunt_try * 25;//총 경험치
        int first_level = level;
        for(i=1;i<=hunt_try;i++){
          int gain=25;//획득 경험치
          exp+=gain;
          if(exp>=100){
            exp-=100;
            level+=1;
            switch(job){
              case 1:
                hp+=20;
                ad+=7;            
                break;
              case 2:
                hp+=10;
                ap+=5;
                break;
              case 3:
                hp+=15;
                ad+=4;
                ap+=3;             
                break;
            }
            power = output_power(job, hp, ad, ap);//함수 호출
          }
        }
        int rise_level = level - first_level;//증가 레벨양
        printf("%d만큼의 경험치를 획득하였습니다\n" , total_gain);
        printf("%d 레벨이 상승하였습니다\n",rise_level);
        status(name, job, level, hp, ad, ap, power);
        printf("사냥이 종료되었습니다.\n");

        
      }
      break;
      
      case(3):
      {
        while(1)
        {
          printf("보스레이드를 시작합니다!\n");
          printf("==============================\n");
          printf("현재 %d 번째 보스등장!\n",boss_level);
          printf("보스의 체력:%.2lf\n",boss_hp);
          printf("보스의 전투력:%.2lf\n",boss_power);
          printf("도전하시겠습니까?(예:1 ,아니오:2)");
          scanf(" %d",&next);
          if(next == 1)
          {
            printf("전투를 시작합니다\n");
            if(power >= boss_power)
            {
              printf("승리! 다음보스로 넘어갑니다\n");
              boss_level++;
              boss_hp = boss_hp * 1.2;
              boss_power = boss_power * 1.4;
            }
            else{
              printf("패배...다시 도전해보세요\n");
              break;
            } 
          }
          else if(next == 2)
          {
            printf("게임을 중지하고 메뉴로 돌아갑니다\n");
            printf("\n");
            break; 
          }
          
        }
        break;   
      } 
    }
  }
  return 0;  
} 
