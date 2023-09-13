# 规范性修改的前后对比

## 案例1

修改前

![image-20220628154550920](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628154550920.png)

修改后

![image-20220628154845502](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628154845502.png)























## 案例2

修改前

![image-20220628155814707](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628155814707.png)

修改后

![image-20220628155619799](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628155619799.png)













## 案例3

修改前

![image-20220628161243624](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628161243624.png)

修改后

![image-20220628161435544](C:\Users\wmy\AppData\Roaming\Typora\typora-user-images\image-20220628161435544.png)

## 三个最有帮助的规范性建议

1. “｝”是否独占一行并与“｛”所在行对齐于同一列。对于清晰程序的结构非常有帮助，类似于`python`中的强制缩进，增强了程序的易读性，有利于检查`{` 的 `}`对应关系。
2. if、for、while、do等语句自占一行，不论执行语句多少都加“｛｝”。
3. 程序中是否出现相同的局部变量和全部变量。个人感觉这是一类非常难发现的bug，

4. 变量命名法（众所周知三个最有帮助的规范性建议有四个）。目前用的比较多的是下划线命名法，采用规范化的变量命名法可以有效的程序中规避出现两个相同名字的变量，尤其是出现相同的局部变量和全局变量，而这一类bug往往很难发现。



