/*************************************************************************
	> File Name: merge_ordered.cpp, modify it to .h; otherwise, link failed!
	> Author: liulianglu
	> Description: merge two ordered list. 
	> Created Time: Sat 23 Sep 2017 04:10:28 AM EDT
 ************************************************************************/


/*
 *  C 语言中，有指针是没有必要使用begin指针的。
 *  这里还是使用大小来表示。
 *  des 的大小要调用者分配足够空间，它的空间为len1+len2
 */
template <typename T>
void merge_ordered(T* des, 
        T* src1, int len1,  T* src2, int len2,
        char (*predicate)(T, T))
{
    int i = 0, j = 0, k = 0;
    while(i < len1 && j < len2)
    {
        if(predicate(src1[i], src2[j]))
        {
            des[k++] = src1[i++];
        }
        else
        {
            des[k++] = src2[j++];
        }
    }

    while(i < len1) des[k++] = src1[i++];
    while(j < len2) des[k++] = src2[j++];
}

