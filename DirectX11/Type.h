#pragma once

class Scene //�߻�Ŭ���� �������̽� interface
{
public:

	virtual ~Scene() {};

	//���������Լ�
	//�� �ʱ�ȭ
	virtual void Init() = 0;
	//�� ����
	virtual void Update() = 0;
	//�� ���
	virtual void Render() = 0;
};

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {};
    static T* GetInstance()
    {
        static T* Instance = new T;
        return Instance;
    };
    void DeleteSingleton()
    {
        delete GetInstance();
    };
};

static float DirToRadian(Vector2 Dir)
{
    //���� �������Ͱ� �ƴҼ��������ϱ�
    Dir.Normalize();
    float Seta;
    if (Dir.y < 0)
    {
        //          360.0*TORADIAN
        Seta = 2.0f * PI - acosf(Dir.x);
    }
    else
    {
        Seta = acosf(Dir.x);
    }
    return Seta;
}
