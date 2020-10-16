### Data Structures

-------------------

A library of data structures in C and C++.

####  概述

------

这是一个关于数据结构的项目，本人系北京化工大学计算机专业大二学生，在数据结构课堂上老师多次强调让我们每学完一种数据结构就去建立一个自己的关于这种数据结构的**库**，我感觉这是一个很powerful的理念，但是，仅仅去自娱自乐的建立这些库，或者单纯为了完成作业而去建立这些库则显得格外的无聊🙃，所以我在github上发起了这个项目。旨在希望有越来越多的同学看到这个项目，并通过github加入到这个项目中来，通过我们共同的努力，建立起一些**编码和接口更加规范，功能更加丰富，实用性更强的库**😉。除此之外，有一件我们不得不去思考的事情，那就是我们建立的这些库到底能够用来做什么，如果我们废了那么大的劲写了一个从代码量上看非常强大的库，却在实际应用时发现他鲜有用武之地（或者仅仅用这些库去解决了OJ上的一些问题），还有比这更加让人失落的事吗😟，所以我更希望通过此项目来积极探索这些**库的实际应用**，可以通过各种奇思妙想利用这些库做一些东西出来，所以，我需要各位同学的加入，通过**Teamwork**来做一些比做作业更加有意思的事情😏！

本项目主要使用C和C++进行开发，非常欢迎你成为此项目的合作者🌹。

#### 通过Github进行团队协作

--------------

如果你不太熟悉git和github的使用，可以通过实验楼的免费课程进行学习，链接如下：

+ [🔗git与github入门与实践](https://www.lanqiao.cn/courses/1035)

我们的协作主要基于以下形式：

+ 通过阅读我已经写好的代码，在项目界面的**Issues**中提出宝贵的建议，主要针对以下问题
  - 代码中的bug🐞（任何有关程序健壮性的问题都是此类问题）
  - 可以使库的功能更加丰富的函数
  - 针对某个函数更好（更高效或更节省内存）的实现方法
  - 更加规范的编码方式（[🔗Google C++编码规范](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/)）

+ 将代码**fork** 到你的账号，对我已经完成的部分进行增加或修改，完成后通过github的**Pull requests**功能提交给我后我对修改进行合并，具体方法可参照如下：

  ​      [🔗如何在github上给开源项目贡献代码](https://www.zhihu.com/question/39721968)

+ 通过联系我，成为项目的合作者，更改完代码后直接push到项目，无需Pull requests，或者，你觉得这个项目挺不错的，但你不想费那么大劲去学习git和github，那么你可以直接通过邮箱联系我，将你写好的修改作为附件发给我，我手动合并后进行提交，并注明此部分代码的贡献者

  ​       本人邮箱📪：**2986565765@qq.com**

非常期待你的加入👊！

#### 项目结构

----------

针对每一个数据结构，我们会将函数声明放在头文件中（后缀为.h），而对于**具体的函数实现我们则放在源文件中（后缀为.c）**，这样做会导致在编译的时候需要用IDE创建工程，好像更麻烦了，但这样做好处多多，而且能够使程序更加规范。注意本项目均不采用IDE建立工程的形式，我们通过**Makefile**来完成整个工程的编译，这样就可以使代码在Linux下通过make命令轻松编译，而在windows环境下，我们只需要用Devc++之类的编译器建立一个工程后将所需要的文件添加进去即可使用。除此之外，针对每个数据结构，都会**有一个README文档📋来描述函数接口和功能**，以及一个main.c文件来对这个库进行测试。

目前已完成部分：

+ Data Structures
  + C
    + [线性表](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/fd65c9cd94c46763a73898f70dbf77984e3010b8/C/lists)
      + [数组实现](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/main/C/lists/ArrayList)
      + [单链表](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/main/C/lists/SinglyLinkedList)
      + [循环链表](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/main/C/lists/CyclicList)
      + [双向链表](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/main/C/lists/DoublyLinkedList)
      + [双向循环链表](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/main/C/lists/DoublyCyclicLinkedList)
  + C++
    + [栈](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/fd65c9cd94c46763a73898f70dbf77984e3010b8/C%2B%2B/stack)
    + [队列](https://github.com/JohnSmithGeek-coder/Data-Structures/tree/fd65c9cd94c46763a73898f70dbf77984e3010b8/C%2B%2B/queue)

