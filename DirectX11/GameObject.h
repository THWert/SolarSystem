#pragma once
class ObLine; //전방선언

class GameObject
{
public:
	static ObLine* axis;

	Vector2 position; //중점
	Vector2 scale; //크기값
	float rotation; //회전값
	bool isAxis;

	Matrix S, R, T, W, RT;
	Matrix* P;

public:
	GameObject();
	virtual ~GameObject();

	//가상함수
	//자식이 재정의 할 것이라고 예상될 때 사용
	virtual void Update();
	virtual void Render();

	static void CreateStaticMember();
	static void DeleteStaticMember();

	//Getter
	Vector2 GetRight()
	{
		return Vector2(RT._11, RT._12);
	}
	Vector2 GetDown()
	{
		return Vector2(RT._21, RT._22);
	}
	Vector2 GetWorldPos()
	{
		return Vector2(RT._41, RT._42);
	}
};

