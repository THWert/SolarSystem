#pragma once
class MainGame : public Scene
{
private:
	ObRect rc1;
	ObRect rc2;
	ObRect rc3;
	ObRect rc4;
	ObRect rc5;

	ObCircle cc1;
	ObCircle cc2;
	ObCircle cc3;
	ObCircle cc4;

public:
	~MainGame() override;
	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

