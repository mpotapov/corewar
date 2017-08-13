.name "zork"
.comment "42just a basic living prog"

live 2

sti: sti	r4,%43,%4

l2:	sti	r1,%:sti,%0 #sdf
	and	r1,%0,r14
live:   live	%1
