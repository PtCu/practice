# 婚姻匹配问题解法  Gale-Shapley算法
    algorithm stable_matching is
    Initialize all m ∈ M and w ∈ W to free
    while some man m is unmatched and hasn't proposed to every woman, do //按男生循环
        w := first woman on m's list to whom m has not yet proposed //该男生最喜欢的女生
        if w is free then
            (m, w) become engaged
        else some pair (m', w) already exists
            if w prefers m to m' then   //该男生最喜欢的女生发现这个男生魅力更大
                m' becomes free 
                (m, w) become engaged 
            else
                (m', w) remain engaged
            end if
        end if
    repeat

    第一轮，每个男人都选择自己名单上排在首位的女人，并向她表白。这种时候会出现两种情况：（ 
    1）该女士还没有被男生追求过，则该女士接受该男生的请求。
    2）若该女生已经接受过其他男生的追求，那么该女生会将该男士与她的现任男友进行比较，若更喜欢她的男友，那么拒绝这个人的追求，否则，抛弃其男友

    第一轮结束后，有些男人已经有女朋友了，有些男人仍然是单身。

    在第二轮追女行动中，每个单身男都从所有还没拒绝过他的女孩中选出自己最中意的那一个，并向她表白，不管她现在是否是单身。这种时候还是会遇到上面所说的两种情况，还是同样的解决方案。直到所有人都不再是单身。

__发现1__： Men propose to women in decreasing order of preference. 男人从高到低找配偶 
__发现2__： Once a women is matched, she never becomes unmatched; she only "trades up". 一旦女生被匹配到，她就不会回到单身，而可能会被“交换”

__claim__: 至多$n^2$步后算法终止。因为每次迭代中每个男人追求的女人都不一样,这样的追求过程至多有$n^2$种 

__claim__: All men and women get matched.
__Pf__:(by contradiction)
- 假设男生M没有找到女朋友，则必然存在一个女生W没有被匹配。由发现2知 Z从未被追求过。但由算法可知要求男生M追求过所有女生。矛盾。
  
__claim__: 没有不稳定对
__Pf__: 反证法：设A-Z是不稳定对，即每个人喜欢对方更胜于当前算法给出的配偶。
- __Case1__: Z never proposed to A. ->From 发现1, Z prefers his GS partner to A. -> A-Z is stable.
- __Case2__: Z proposed to A. -> A rejected Z(right away or later) -> A prefers her GS partner to Z. -> A-Z is stable.


__Def.__. Woman w is a valid partner of man m if there exists some stable matching in which they are matched. (若存在稳定匹配使得女生w是男生m的有效伴侣，则称w是m的有效伴侣)

__Man-optimal assignment__. Each man recives best valid partner.

__Claim__. All executions of GS yield __man-optimal__ assignment. which is a stable matching!

每个男生都找到了最好的有效伴侣，每个女生都找到了最差的有效伴侣。（可反正）

## 总结：
__statble matching problem__ 
- 给出男性女性的偏好列表，找到最优匹配。
- Gale-Shapley算法可以在O(n^2)时间内找到一个稳定匹配
- 每个男性都能找到自己最喜欢的有效伴侣——按照此算法，男性没有动机去掩饰自己的喜好
- 每个女性找了的最差的有效伴侣——按照此算法，女性有可能掩饰自己的喜好——女生可以通过说谎来得到更好的结果
  
应用：医生和科室匹配、器官捐献等