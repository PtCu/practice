#include <bits/stdc++.h>
using namespace std;
struct Lecture
{
    float start_time;
    float finish_time;
};

int main()
{
    int num;
    cout << "请输入讲座的数目:" << endl;
    cin >> num;
    vector<Lecture> lectures(num);
    cout << "请依次输入讲座的开始时间、结束时间:" << endl;
    for (int i = 0; i < num; ++i)
    {
        cin >> lectures[i].start_time >> lectures[i].finish_time;
    }

    sort(lectures.begin(), lectures.end(), [](const Lecture &a, const Lecture &b) { return a.start_time < b.start_time; }); //按开始时间小的排序

    priority_queue<double, vector<double>, greater<double>> classrooms; //小顶堆。每个教室最晚结束时间

    classrooms.push(0);

    for (int i = 0; i < num; ++i)
    {
        //如果讲座开始时间大于该教室结束时间
        if (lectures[i].start_time >= classrooms.top())
        {
            //将教室最早结束时间替换成该讲座的结束时间
            classrooms.pop();
            classrooms.push(lectures[i].finish_time);
        }
        else
        {
            //开辟一个新教室，将该新教室的使用时间保存
            classrooms.push(lectures[i].finish_time);
        }
    }
    cout << "需要教室的最大数目:" << endl;
    cout << classrooms.size() << endl;

    return 0;
}