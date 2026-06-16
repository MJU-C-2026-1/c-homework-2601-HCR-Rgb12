/* 
  파일이름: main.c
  작 성 자:60232361 류형찬
  하 는 일: RPG 형식의 캐릭터 생성 및 보스 잡기 게임 4.0
*/

#include <stdio.h>
const int PARTY_SIZE = 3;//파티 인원수 상수로 지정
//함수 파트
//메인메뉴의 함수화
void print_menu()
{
  printf("C언어RPG 게임에 오신 걸 환영합니다!\n"); 
  printf("===============================\n");
  printf("메뉴를 선택해주세요\n");
  printf("1.캐릭터 생성\n");
  printf("2.파티정보 확인\n");
  printf("3.사냥터 입장\n");
  printf("4.보스 레이드\n");
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
void status(char name[][30], int job[],int level[], int hp[], double ad[],double ap[],double power[])
{
  int p;//반복문 변수
  printf("==========================\n");
  printf("현재 파티스텟 상황입니다\n");
  for(p=0;p < PARTY_SIZE;p++)
  {
    printf("%d번째 파티원의 스텟입니다\n",p+1);
    printf("이름:%s,레벨:%d,체력:%d,공격력:%.2lf,마력:%.2lf,총 전투력:%.2f \n",name[p],level[p],hp[p],ad[p],ap[p],power[p]);
  }
   printf("==========================\n");
   printf("\n");
}
//전역변수-보스 전투때 사용
double party_power;//파티 총합 전투력
int boss_level = 1;
double boss_hp = 850;
double boss_power = 800;

int main(){
  char name[PARTY_SIZE][30];
  int menu;//메뉴화면 입장변수
  int job[PARTY_SIZE];// 번호를 입력받아 직업 설정
  int hp[PARTY_SIZE]; //체력
  double ad[PARTY_SIZE]; //물리 공격력
  double ap[PARTY_SIZE]; //마법 공격력
  double faith[PARTY_SIZE]; //신앙심(성직자의 주요스텟)
  double power[PARTY_SIZE];// 총 전투력
  int level[PARTY_SIZE];//각 파티원 레벨
  int exp[PARTY_SIZE];//경험치량
  int hunt_try;//사냥터 진행 횟수
  int i,j; //반복문 변수
  int next; //보스 입장 여부 확인 변수
  for(i=0;i<PARTY_SIZE;i++)
  {
    level[i] = 1;
    exp[i] = 0;
    ad[i] = 0;
    ap[i] = 0;
    power[i] = 0;
  }

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
        printf("3명의 캐릭터를 생성합니다\n");
        for(i=0;i<PARTY_SIZE;i++)
        {

          printf("%d번째 캐릭터 생성\n",i+1);
          printf("캐릭터의 이름을 입력해주세요:");
          scanf(" %s", name[i]);
          printf("원하는 직업을 선택해주세요:1.전사,2.마법사,3.성직자:");
          scanf("%d", &job[i]);
          switch(job[i])
          {
            case 1:
              printf("전사를 고르셨습니다\n");
              printf("체력 입력(1포인트당1.5):");  
              scanf("%d",&hp[i]);
              printf("공격력 입력(1포인트당 1.3):");
              scanf("%lf",&ad[i]);
              break;

            case 2:
              printf("마법사를 고르셨습니다\n");
              printf("체력 입력(1포인트당 0.9):");  
              scanf("%d",&hp[i]);
              printf("마력 입력(1포인트당 2.2):");
              scanf("%lf",&ap[i]);
              break;

            case 3:
              printf("성직자를 고르셨습니다\n");
              printf("체력 입력(1포인트당 1.2):");  
              scanf("%d",&hp[i]);
              printf("공격력 입력(1포인트당 1.2):");
              scanf("%lf",&ad[i]);
              printf("마력 입력(1포인트당 1.4):");
              scanf("%lf",&ap[i]);
              break;
          }//직업 선택 및 스텟 설정 끝
          power[i] = output_power(job[i], hp[i], ad[i], ap[i]);//함수 호출
        }        
        break;
        printf("\n");
      } 

      case(2):
      {
        status(name, job, level,hp,ad,ap,power);
        double party_power = 0;
        for(i=0;i < PARTY_SIZE;i++)
        {
          double *ptr = power;
          party_power+=*(ptr+i);//파티 전투력 포인터 연산
        }
        printf("총합 전투력:%.2lf \n",party_power);
        printf("=======================\n");
        printf("\n");
        break;
      }

      case(3):
      {
        printf("사냥터에 오신 것을 환영합니다!\n");//사냥터를 통한 경험치 획득 및 레벨업 수식
        printf("사냥횟수를 입력하세요:");
        scanf("%d", &hunt_try);
        int rise_level = 0;//증가 레벨양
        int total_gain = hunt_try * 25;//총 경험치
        for(i=0;i<PARTY_SIZE;i++)
        {
          int first_level = level[i];
          for(j=1;j<=hunt_try;j++){
            int gain=25;//획득 경험치
            exp[i]+=gain;
            if(exp[i]>=100){
              exp[i]-=100;
              level[i]+=1;
              switch(job[i]){
                case 1:
                  hp[i]+=20;
                  ad[i]+=7;            
                  break;
                case 2:
                  hp[i]+=10;
                  ap[i]+=5;
                  break;
                case 3:
                  hp[i]+=15;
                  ad[i]+=4;
                  ap[i]+=3;             
                  break;
              }
            }  
          }
          power[i] = output_power(job[i], hp[i], ad[i], ap[i]);//함수 호출 
          rise_level = level[i] - first_level;//증가 레벨양
        } 
        printf("모든 파티원이 %d만큼의 경험치를 획득해 %d레벨이 상승했습니다\n",total_gain,rise_level);
        printf("사냥이 종료되었습니다.\n");
        printf("\n");
        break;
      }
      
      
      case(4):
      {
        while(1)
        {
          printf("보스레이드를 시작합니다!\n");
          printf("==============================\n");
          printf("현재 %d 번째 보스등장!\n",boss_level);
          printf("보스의 체력:%.2lf\n",boss_hp);
          printf("보스의 전투력:%.2lf\n",boss_power);
          double party_power = 0;
          for(i=0;i<PARTY_SIZE;i++)
          {
            double *ptr = power;
            party_power = *(ptr+i);//위와 동일한 포인터 연산
          }
          printf("현재 파티 전투력은 %.2lf 입니다\n",party_power);
          printf("도전하시겠습니까?(예:1 ,아니오:2)");
          scanf(" %d",&next);
          if(next == 1)
          {
            printf("전투를 시작합니다\n");
            if(party_power >= boss_power)
            {
              printf("승리! 다음보스로 넘어갑니다\n");
              boss_level++;
              boss_hp = boss_hp * 1.2;
              boss_power = boss_power * 1.4;
              if(boss_level == 11)
              {
                printf("축하드립니다! 모든 보스를 클리어하셨습니다!\n");
                printf("\n");
                break;
              }
            }
            else{
              printf("패배...다시 도전해보세요\n");
              printf("\n");
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
