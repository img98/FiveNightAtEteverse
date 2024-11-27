
# Five Night At Eteverse

[![FNAE유튜브이미지](http://img.youtube.com/vi/6bcxpOHsBZQ/0.jpg)](https://youtu.be/6bcxpOHsBZQ)

FiveNightAtEteverse는 VR기기를 사용하여 즐길 수 있는 실감형 프로젝트입니다.

오큘러스 퀘스트를 사용하여 가상의 공간에 들어가 사물을 직접 만지고 상호작용하는 컨텐츠를 제작했습니다.


# 세부 사항

- 개요 : 한밤 중의 사무실에 남아 야간 당직을 서는 주인공. 하지만 건물에서는 귀신이 나온다는 소문이 들린다. 문을 닫거나 캐비넷에 숨어 귀신을 피하며 무사히 아침을 맞이하자.
- 목적 : 에티버스 러닝 과정에서 개인 프로젝트로 제작한 VR 호러 게임입니다. 언리얼 엔진5를 사용하여 만든 가상 공간을 탐험하며 VR기기를 통해 현실 같은 경험을 제공합니다.
- 개발 기간 : 2024.09.19 ~ 2024.09.25


# 컨텐츠 및 기능

## 실시간 렌더링

플레이어는 사무실에서 건물 내 공간을 CCTV를 통해 감시합니다.

USceneCaptureComponent2D를 사용하는 가상의 CCTV 카메라를 구현하여, 게임 속 상황을 촬영합니다.

촬영 된 화면은 RenderTarget을 통해 실시간으로 갱신되는 텍스쳐를 생성하며, 이것을 사무실 내 모니터에 표시합니다.

![cctvcam](https://github.com/user-attachments/assets/5a7d5e23-6c58-4c19-bb9f-25894ad06108) |![cctvmonitor](https://github.com/user-attachments/assets/a6ee6687-d9df-46e0-bf02-3ddb1854b051)
--- | --- | 


## 회피 기믹 - VR 상호작용

VR기기를 조작하여 가상공간 내 물체들과 현실처럼 상호작용 할 수 있습니다.

키카드를 손으로 집어 문을 닫거나, 캐비넷 손잡이를 열고 닫아 내부에 숨어 적합한 회피 기믹을 수행해야 합니다.

![vrkeycard](https://github.com/user-attachments/assets/91dd5518-0229-42de-ba95-2c88ffaadd88)) |![vrcabinet](https://github.com/user-attachments/assets/e6c522fb-3b4f-4e79-88bb-5497c5b019ad)
--- | --- | 
> [DoorLock 링크](https://www.notion.so/DoorLock-ce6f06ab975e49c4ac7f6ee7f841d85c?pvs=21)

> [HideSpot 링크](https://www.notion.so/HideSpot-f6d1b345f6a747f8997678ba02220291?pvs=21)
    
## 몬스터

BaseMonster를 상속받는 2가지 몬스터(귀신)를 제작했습니다.

Enum을 통해 몬스터의 행동상태를 구분하고, 각 상태에 맞춰 진행하는 BehaviorTree를 만들었습니다.

모든 몬스터는 같은 BehaviorTree를 사용하여 플레이어에게 접근하고 기믹 수행 여부를 검사한다는 공통적인 행동을 취하지만, Task에서 요구하는 기믹 판단 함수를 가상함수로 제작하여, 각각의 몬스터는 다른 논리 하에 회피 여부를 판단합니다.

이를 통해, 새로운 몬스터 추가 시, 매번 새로운 행동양식을 제작할 필요 없이 판단 함수만 수정하도록 설계하였습니다.

1. DoorMonster는 플레이어의 '문 잠금 여부'를 확인
2. HideMonster는 플레이어의 '은신 여부'를 확인

![BT](https://github.com/user-attachments/assets/bf457bf1-6b4e-437b-828f-04185dc7a661) |![Task](https://github.com/user-attachments/assets/281998a5-022c-4802-93e8-5b637ee6d1b7)
--- | --- | 

```cpp

//DoorMonster.cpp
bool ADoorMonster::CheckPlayerStateSafe()
{	
	...
	if (GameState->GetIsDoorLocked())
	{
		return true;
	}
}

//HideMonster.cpp
bool AHideMonster::CheckPlayerStateSafe()
{
	...
	if (GameState->GetIsPlayerHide())
	{
		return true;
	}
}
```
    
>[MonsterCharacter 링크](https://www.notion.so/MonsterCharacter-42ce0f29748d40c0b5d1ef7f6a82d1be?pvs=21)


# 플레이 영상

> https://youtu.be/6bcxpOHsBZQ
