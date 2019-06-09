#include <vector>
int BinarySearch(std::vector<int> &a, int key)
{
    /** \brief ʹ�ö��ַ���������ai-1<key��ai>=key��iֵ
     *
     * \param a �ؼ��ֵ�����������
     * \param key �����ؼ���
     * \return ����Ҫ���iֵ��û�з���-1
     *
     */
    int low = 0;
    int len = a.size();
    int high = len - 1;
    int middle;
    // ������Ҫ�󷵻�-1
    if(key>a.at(high) || key<=a.at(low))
    {
        return -1;
    }
    while(low<=high)
    {
        middle = (low + high) / 2;

        // ����պ�����Ҫ�󣬷���λ��
        if(a.at(middle)>=key && a.at(middle-1)<key)
        {
            return middle;
        }
        // С�����ں�벿�ֲ���
        else if(a.at(middle)<key){
            low = middle + 1;
            middle = (low + high) / 2;
        }
        // ��������ǰ�벿�ֲ���
        else if(a.at(middle-1)>=key){
            high = middle - 1;
            middle = (low + high) / 2;
        }
    }
    return middle;
}
