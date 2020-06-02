/*
思路：辅助栈
参考tony的，利用两个栈，思路清晰。
*/
class Solution
{
public:
    /*
     * 双栈处理，一个栈放数字，一个栈放字符串，然后逐个退栈后叠加到输出字符串中
     */
    string decodeString(string s)
    {
        vector<int> dataStk;
        vector<string> strStack;

        int num = 0;
        string strTemp = "";

        for (int i = 0; i < s.length(); ++i)
        {
            char temp = s[i];

            // 把当前累加的数字计算出来
            if (isdigit(temp))
            {
                num = num * 10 + temp - '0';
                continue;
            }

            // 叠加字符串
            if (isalpha(temp))
            {
                strTemp.push_back(temp);
                continue;
            }

            // 当出现“[”时处理数字和字符串，其中0和空串也要入栈，否则后面出栈就会出现不匹配问题
            if (temp == '[')
            {
                dataStk.push_back(num);
                num = 0; //倍数num清零。

                strStack.push_back(strTemp); //comment1
                strTemp = ""; //字符串strTemp清空。

                continue;
            }

            // 当遇到“]”时计算结果
            //拼接字符串 res = last_res + cur_multi * res,last_res是上个 [ 到当前 [ 的字符串，例如 "3[a2[c]]" 中的 a。
            if (temp == ']')
            {
                //数字和字符串转化：比如2[c]转化为cc。
                int count = dataStk.back();
                dataStk.pop_back();
                string resTemp = "";
                for (int k = 0; k < count; k++)
                    resTemp.append(strTemp); //comment2              
                //之后若还是字母，就会直接加到strTemp之后，因为它们是同一级的运算,若是左括号，strTemp会被压入strStack栈，作为上一层的运算
                strTemp = strStack.back() + resTemp; //comment3
                strStack.pop_back(); //3[a2[c]],第一次出栈的是"acc"字符串，这个"acc"字符串会在comment1或者comment2处重新加到comment3处的strTemp里。
            }
        }

        return strTemp;
    }
};
