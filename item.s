/* Assembly function that increments item counter*/
.global item_count

item_count:
.top:    
    add r0, r0, #1
    b .end
.end:
    mov pc, lr
 
