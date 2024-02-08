당근설정
------

전방차간거리 및 주행설정
------
* 전방차량과의 거리 설정
* 핸들리모컨의 거리설정으로 변경가능
* 차간거리 설정  
  * Carrot(당근메뉴)
    * Cruise
      * GAPx: Apply TFollow
        * x단계(1~4단계)별로 차간거리 설정 (핸들리모컨으로 설정함)
        * 각설정은 시간을 말하며, 유지거리 = 설정값*0.01초 x 속도
        * 1.2초(90) 이하로 하면, 위험할수 있으니 주행시 신중히 전방주시해야함
          * Carrot의 감속도는 최대 4.0m/s^2이다. 하지만 운전자가 급정거시에 발생되는 감속도는 5~10m/s^2에 육박한다. 그만큼 감속력이 부족하다는 뜻을 말하므로, 사람이 감속하는것 만큼 기대하면 사고가 날 수 있다.
      * Additional TFs 40km/h
        * 0~40km/h까지 점차적으로 차간거리를 늘려감
        * 예) 값을 0.2초로 설정하고, 1단계 Follow Time이 1.0초일때: 정지상태에서는 1.0초이지만, 40km/h일때는 1.2초가 됨.
      * Additional TFs 100km/h
        * 40km/h ~ 100km/h까지 점차적으로 차간거리를 늘려감
        * 예) 값을 0.4초로 설정하고, 1단계 Follow Time이 1.0초일때: 정지상태는 1.0초, 100km/h일때는 1.4초가 됨.(40km/h까지는 Additional TFs 40km/h값이 적용됨)
  * 관련설정: 주행모드 설정
    * 주행모드에 따라서, 설정된 GAP거리가 증가됨.
       
주행모드 설정
------
  * 차량의 주행모드 설정
  * 핸들리모컨의 거리설정을 길게누르면 변경됨 
  * Carrot(당근메뉴) -> Cruise
    * DRIVEMODE: Select
      * 1: 연비모드 
      * 2: 안전모드
      * 3: 일반모드
      * 4: 고속모드
        * 일반모드에서 신호감지기능만 정지됨
    * DRIVEMODE: Eco ratio (90)%
      * 연비모드일때 적용율선택
      * 가속도, 정지거리, 차간거리가 적용율만큼 적용됨
    * DRIVEMODE: Safe ratio
      * 안전모드일때 적용율선택
      * 가속도, 정지거리, 차간거리가 적용율만큼 적용됨

주행튜닝
------
  * 롱컨주행의 민감도를 설정함  
  * 당근맨 -> SET -> 주행튜닝
    * aLeadTauStart (50)x0.01 m/s^2
      * 선행차의 가속도에 대한 민감도 설정
      * 숫자가 적으면 약간의 움직임에도 반응함.
    * aLeadTau (150)x0.01
      * 선행차의 가속도에 대한 반응정도 설정
      * 숫자가 적으면 반응이 적극적임.
    * AChangeCost(200)
      * 속도프로파일 생성시 가속도를 제한하는 가중치
      * 값이 적으면 가속도변화율이 커짐
    * AChangeCostStart(40)
      * 정지 출발시 가속도를 제한함.
      * 값이 적으면 출발가속도가 높아짐.
    * LADLowerBound(50)/LADUpperBound(50)  * 0.01 sec
      * Longitudinal Actuator Delay Upper/Lower Bound
      * 일종의 차량 지연현상을 보상하는것임. 0.5초로 설정하는것이 가장 무방함.
    * 현기차(Hyunda/Kia)참조
      * Kf게인(100)
        * 현기차는 100으로 고정
      * KiV게인(400)
        * 정지시 불안전한 정지거리를 보상하기 위해 400정도 세팅하는것이 좋음...
        * 0으로 해도 현기차는 잘함.
      * KpV게인(100)
        * 현기차는 100으로 고정        
      * TODO: JerkUpper/LowerLimit와 ComfortLower/UpperBound의 영향이 매우큼.
        * 적당한 수식을 세워서 넣어놨으나, 향후 좀더 편안한 주행을 위해서 조절할 필요가 있음.

정지튜닝
------
* 차량의 정지에 대한 튜닝이다.
* StopDistance(600)cm
  * 일반적으로 LEAD_DANGER_FACTOR(0.75)  x StopDistance : 400cm정도에서 정지한다.
* 정지시작가속도  (-80) x 0.01 m/s^2
  * 이로직에는 문제가 있어보이지만....
  * -0.8 m/s^2의 가속도에서 정지유지 브레이크를 걸기 시작한다.
  * 올리면 올릴수록 정지충격이 덜하지만 차량이 흐르는? 그런문제가 발생한다.
* 정지유지브레이크 -2.0 x(50%)
  * 정지를 하고 있을때 유지할 브레이크압력을 준다.
* 초기가속도2.0x(0%)  
  * 차량에 따라서 사용되는경우가 있으나, 일반적으로 사용하지 않는다.
  * 정지출발시, pid제어를 하기전에 적당한 가속도(설정값)를 주어 속도가 어느정도 올라가면 pid제어를 시작하는 방식으로, 출발시 급격한 출발이 발생할때 사용된다.
  * 일반적인 현기차는 가속도명령을 주어도 약 1초뒤에 반응하는데, 이때 급격한 출발을 하는경우가 많다.
* 완전정지시 충격방지방법
  * 정지유지브레이크: 0 (필요없는 설정같다)
  * 정지시작가속도: -40 (밀리는 경향이 있으면, 살짝낮추어준다)

조향튜닝
------
* SteerActuatorDelay(40) msec
  * 조향장치의 지연시간이다. 약 30~40msec정도의 지연시간을 갖는것 같다. 그래프를 보면서 튜닝해야겠지만, 실제 40msec정도면 적당한듯한다.
  * 값이 크면 조향을 미리 하게 되어, 와리가리 현상이 생길것 같다는 생각이 든다.
* SteerRatioCustomx0.1(0)
  * Controls(개구리메뉴) -> Lateral Tuning -> Manage -> SteerRatio
  * 차량마다 조향의 SteerRatio라는게 있다. 일종의 감속도라고 봐야할것 같다.
  * 감속도라고 하면 정확히 입력하면 되지만, 여러가지 변수로 인해 적당히 조절된 값으로 이용해야 맞는것 같다.
  * 오픈파일럿 스톡에서는 LiveSteerRatio로 측정치를 사용하는데, 뭔가 좀 문제가 있어보인다. 따라서, 일반적으로 고정SteerRatio를 사용한다.
  * 차량의 기본값을 참조하여 입력하도록 한다.
  * 값이 작으면 조향을 많이한다. 연속된 커브길을 운행하면서 값을 찾는것이 좋다. (당근의 디버그화면을 켜면 liveSR값이 표시되는데, 일반적으로 이값보다 90%의 값을 사용하면 맞는듯하다)
* _LateralTorqueCustom(0)
  * 조향은 일반적으로 토크제어를 한다.
  * 콤마스톡은 학습에 의해 토크제어를 하는데, 이 학습기간이 생각보다 길다. 약 40km정도를 주행해야 완료되는것 같다.
  * 하지만, 학습값도 별로 맘에들지는 않는다.
  * 이값을 1로 하면 custom값을 사용한다.
* _LateralTorqueAccelFactor*0.001(2500)
  * Custom AccelFactor값
  * 값이 작아지면 조향토크가 증가된다.
  * 계속낮춰가며, 핸들의 움직임이 둔탁해질때까지 내린다. 요기서 둔탁하지 않을정도 까지 살짝올려주면 가장좋은값이 아닌가? 라는 개인적인 생각이다.
  * 참고: 개인적인 생각으로 튜닝한것임.
* _LateralTorqueFriction*0.001(100)
  * Custom Friction값
  * 이값은 정지기동시 조향토크에 추가되는 값이다.
  * 값을 너무 크게하면 부드럽지 못한 핸들링이 되는것이 확인된다.
  * 참고: 개인적인 생각으로 튜닝한것임.
* MaxAngleFrames(89)
  * 현기차는 조향제어시 일정 각도를 넘어가면, Steering fault가 난다고한다. 이때, 강제로 fault신호를 주기적으로 넣어주면 증상이 없어진다.
  * 기본값은 89이지만, 차량에 따라 85정도를 넣어야 안나는 차량도 있다고 한다.
  * 그냥 87정도 넣어놓자..

조향튜닝(차선추적모드)
------
* 차선추적모드란?
  * 콤마는 차선추적기능을 삭제하였다. 이 기능을 사용하지 않아도 충분히 좋은 성능을 낸다.
  * 상황에 따라서 이기능이 필요한경우가 있어서 넣게 되었다.
  * 이 기능을 활성화하면, 콤마모델에서 제공하는 lateral planner를 사용하지 않고, 과거의 lateral planner를 사용하게 된다.
* 당근 차선 추적모드의 특징
  * 가장자리 차선의 경우 좀더 가장자리로 주행하도록 유도한다. (AdjustLaneOffset)
  * 커브길의 경우 안쪽으로 유도한다. (AdjustCurveOffset)
  * 차선이 일시적으로 1개만 나오는 경우 약 5초간 차선폭값을 유지하도록 하여, 정상적인 차선추적이 가능하도록 함. 이후에는 속도에 따른 가상의 차선폭을 만들어 차선을 따라가게 된다.
* 차선추적모드활성화
  * Laneline mode speed(0) km/h
    * 0으로 설정하면, 비활성화 되며 콤마의 모델 조향 플래너를 사용하게 된다.
    * 1이상으로 설정하면 차선추적모드가 활성화된다.
      * 50으로 설정하면, 50이하의 속도에서는 콤마가 제공하는 주행경로를 따라가며, 그이상의 속도에서는 차선을 따라가게 된다.
      * 양쪽 차선이 보이지 않거나, 차선변경시 콤마가 제공하는 주행경로를 따라간다.
  * AdjustLaneOffset (0) cm
    * 도로의 끝차선에서 주행하고 있을때, 지정된 거리만큼 살짝 주행경로를 이동시켜 안정된 주행이 되도록 유도한다.
    * 좌우차선이 넓거나 좁으면 작동하지 않는다.
    * 주행차선이 좁으면, 작동하지 않는다.
  * AdjustCurveOffset (0) cm
    * 커브길을 만나면 안쪽으로 경로를 이동하여, 안정된 커브가 되도록 유도한다.


주행일반(크루즈제어)
------
* 크루즈버튼설정
  * 크루즈버튼작동모드(0)
  * 크루즈버튼속도단위(10) 
* 자동크루즈설정
 * 현기차는 자동크루즈 제어를 지원한다. 이것을 사용하면 아주 편한운전이 가능하다.
 * 일시적으로 원치않을때
   * 주차장과 같은 곳에서는 아주 안좋다.
   * 핸들리모컨의 크루즈 CANCEL버튼을 눌러준다.
   * 다시 재개할때는 Res(+)/Set(-) 버튼을 눌러주면 된다.
  * 오토크루즈제어(HKG only)
    * 0: 사용안함
    * 1: 사용함
    * 2: 사용함, 브레이크/악셀 해제상태에서 전방의 장애물로 다가갈때 자동으로 크루즈ON
  * 소프트오토홀드기능(HKG only)
    * 0: 사용안함
    * 1: 사용함
    * 2: 사용함, SCC제어 (계기판에 오류가 발생하면 끈다)
  * 오토크루즈 관련 설정
    * 브레이크해제크루즈ON:주행,신호
    * 엑셀크루즈OFF:모드
    * 엑셀크루즈ON:속도
    * 크루즈ON거리
* 크루즈속도제어
  * 자동속도증가모드
  * 크루즈연비제어


NOO Helper
------
* 기능소개
  * 오픈파일럿에는 NOO(Navigate On Openpilot)기능이 있다.
  * 원래 이 기능은 실험적모드(Experimental mode)에서만 작동되도록 설계되었지만, 당근에서는 일반모드에서도 작동되도록 수정하였다.
    * 실험적모드는 주행속도를 너무 과하게 줄여놔서, 실사용이 거의 불가능하다.
  * NOO는 차선변경과 턴을 지원하긴 하지만, 실험적 모드를 사용하지 않으면 속도제어가 안되며, 차선변경을 지원하지 않는다.(조금은 하는것 같음)
  * NOO Helper는 주행속도를 제어하고 도로경계에 있을때, 자동으로 차로변경을 해준다. 단, 깜박이는 못켜줌.
  * 레이더트랙이 지원되는 차량은 레이더 정보를 이용하여, 변경하고자 하는 차선의 장애물을 인식하여 방지해주어 훨씬 낳은 Noo Helper가 작동될수 있다.
  * 레이더 트랙이 지원하지 않는 차량은 3번(반자동)을 선택하여, 핸들만 살짝 돌려주면 자동으로 차선변경해주는 기능으로 사용해야한다.
* 작동조건
  * 당근맨으로부터 TBT정보를 수신 받을때만 작동한다.
  * 당근맨이 작동되는 네비게이션 앱을 설치해야만 작동된다.
  * Mapbox의 pk,sk token을 받아서 등록하면 당근에 맵이 작동되며, 오파의 NOO가 작동된다.
* 진행중............





작업중
------
      
* Carrot(당근메뉴)
  * Start    
  * Cruise
  * Speed
  * Tuning
  * Disp
  * Path
* Visuals(화면)