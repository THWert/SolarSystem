#include "framework.h"

GameObject::GameObject()
{
	position = Vector2(0.0f, 0.0f);
	scale = Vector2(1.0f, 1.0f);
	rotation = 0.0f;
	isAxis = false;
	P = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	S = Matrix::CreateScale(scale.x, scale.y, 1.0f);
	R = Matrix::CreateRotationZ(rotation);
	T = Matrix::CreateTranslation(position.x, position.y, 0.0f);
	RT = R * T;

	if (P)
	{
		RT *= *P;
	}

	W = S * RT;
}

void GameObject::Render()
{
	if (isAxis)
	{
		//x��
		axis->position = GetWorldPos();
		axis->scale.x = scale.x;
		axis->rotation = DirToRadian(GetRight());
		axis->Update();
		axis->Render();

		//y��
		axis->scale.x = scale.y;
		axis->rotation = DirToRadian(GetDown());
		axis->Update();
		axis->Render();
	}
}

ObLine* GameObject::axis = nullptr;

void GameObject::CreateStaticMember()
{
	axis = new ObLine();
}

void GameObject::DeleteStaticMember()
{
	delete axis;
}
