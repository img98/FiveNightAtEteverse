
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

플레이어는 사무실에서 건물 내의 공간을 CCTV를 통해 감시합니다.   RenderTarget을 통해 실시간으로 갱신되는 텍스쳐를 생성하여 사무실 내 모니터에 표시합니다.

![cctv.png](https://caramel-tin-182.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fbef6d7ee-7f0a-430a-8892-e359dcd59377%2F18dd57d0-b058-421c-8b44-b9507e8c3333%2Fcctv.png?table=block&id=13dd2bcf-8882-80d7-bdda-d5e6561581b1&spaceId=bef6d7ee-7f0a-430a-8892-e359dcd59377&width=860&userId=&cache=v2)

[RenderTarget_CCTV 링크](https://www.notion.so/CCTV-12fe42954b5f4f248b52cefb1fba2ce7?pvs=21)

## 회피 기믹 - VR 상호작용

VR기기를 조작하여 가상공간 내 물체들과 현실처럼 상호작용 할 수 있습니다.

키카드를 손으로 집어 문을 닫거나, 캐비넷 손잡이를 열고 닫아 내부에 숨어 적합한 회피 기믹을 수행해야 합니다.

<p align="center">
  <img src="https://caramel-tin-182.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fbef6d7ee-7f0a-430a-8892-e359dcd59377%2F9544e5d5-b0a4-457f-a61a-2e7e0397a869%2Fdoorlock.png?table=block&id=13dd2bcf-8882-8096-a00e-f27c5cb69752&spaceId=bef6d7ee-7f0a-430a-8892-e359dcd59377&width=670&userId=&cache=v2" alt="doorlock" width="45%">
  <img src="https://caramel-tin-182.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fbef6d7ee-7f0a-430a-8892-e359dcd59377%2F80160558-fe46-4ddf-adab-0c61e7fc2aae%2Fcabinet.png?table=block&id=13dd2bcf-8882-80b1-93f9-e8a18733e5e7&spaceId=bef6d7ee-7f0a-430a-8892-e359dcd59377&width=670&userId=&cache=v2" alt="cabinet" width="45%">
</p>

> [DoorLock 링크](https://www.notion.so/DoorLock-ce6f06ab975e49c4ac7f6ee7f841d85c?pvs=21)

> [HideSpot 링크](https://www.notion.so/HideSpot-f6d1b345f6a747f8997678ba02220291?pvs=21)
    
## 몬스터

BaseMonster를 상속받는 2가지 몬스터(귀신)를 제작했습니다.

각각의 몬스터는 같은 BehaviorTree를 사용하지만 Task에서 요구하는 함수를 가상함수로 만들었기에 다른 대처를 해야합니다.

1. DoorMonster는 플레이어의 문 잠금 여부를 확인
2. HideMonster는 플레이어의 숨은 상태 확인
    
![image.png](https://caramel-tin-182.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fbef6d7ee-7f0a-430a-8892-e359dcd59377%2F4e9b7219-b5a1-40bc-b6c9-17867aba2a01%2Fimage.png?table=block&id=13dd2bcf-8882-8064-9f76-ce6979d07709&spaceId=bef6d7ee-7f0a-430a-8892-e359dcd59377&width=1420&userId=&cache=v2)

```cpp

//DoorMonster.cpp
bool ADoorMonster::CheckPlayerStateSafe()
{
	if (GameState->GetIsDoorLocked())
	{
		return true;
	}
}

//HideMonster.cpp
bool AHideMonster::CheckPlayerStateSafe()
{
	if (GameState->GetIsPlayerHide())
	{
		return true;
	}
}
```
    
>[MonsterCharacter 링크](https://www.notion.so/MonsterCharacter-42ce0f29748d40c0b5d1ef7f6a82d1be?pvs=21)


#플레이 영상

> https://youtu.be/6bcxpOHsBZQ