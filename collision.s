/* Assembly function that increments collision counter, once 10 collisions have been made a message is displayed*/
.global collision_count

collision_count:
.top:    
    add r0, r0, #1
    cmp r0, #10
    bge .ten
    b .end
.ten:
    mov pc, lr
.end:
    mov pc, lr
 
