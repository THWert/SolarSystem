#pragma once
class ObLine; //���漱��

class GameObject
{
public:
	static ObLine* axis;

	Vector2 position; //����
	Vector2 scale; //ũ�Ⱚ
	float rotation; //ȸ����
	bool isAxis;

	Matrix S, R, T, W, RT;
	Matrix* P;

public:
	GameObject();
	virtual ~GameObject();

	//�����Լ�
	//�ڽ��� ������ �� ���̶�� ����� �� ���
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

