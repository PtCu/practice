Anonymous unions—匿名联合
在 C++ 我们可以选择使联合(union)匿名。如果我们将一个 union 包括在一个结构(structure)的定义中，并且不赋予它对象(object)名称 (就是跟在

花括号{}后面的名字)，这个union 就是匿名的。这种情况下我们可以直接使用 union 中元素的名字来访问该元素，而不需要再在前面加 union 对象的名称。

在下面的例子中，我们可以看到这两种表达方式在使用上的区别：

    
**union**

    struct {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    } price;
    } book;


**anonymous union**

    struct {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    };
    } book;

以上两种定义的唯一区别在于左边的定义中我们给了 union 一个名字 price ，而在右边的定义中我们没给。

在使用时的区别是当我们想访问一个对象(object)的元素 dollars 和 yen 时，在前一种定义的情况下，需要使用：

 

　　　　book.price.dollars;

　　　　book.price.yen;

而在后面一种定义下，我们直接使用：

　　　　book.dollars;

　　　　book.yen;

 

再一次提醒，因为这是一个联合(union)，域 dollars 和 yen 占据的是同一块内存空间，所以它们不能被用来存储两个不同的值。也就是你可以使用

一个 dollars 或 yen 的价格，但不能同时使用两者。