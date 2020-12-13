; Filename: controller1.inc
; Description: Game controller 1 file
; Author: David Brousseau

; Read controller 1 input
    LDA #$01
    STA $4016
    LDA #$00
    STA $4016
    LDA $4016
    LDA $4016
    LDA $4016
    LDA $4016

; Upper direction pad button
    LDA $4016
    AND #00000001
    CMP #1
    BNE lowerPad1
    LDA #1
    STA direction

; Lower direction pad button
lowerPad1:
    LDA $4016
    AND #00000001
    CMP #1
    BNE leftPad1
    LDA #2
    STA direction

; Left direction pad button
leftPad1:
    LDA $4016
    AND #00000001
    CMP #1
    BNE rightPad1
    LDA #3
    STA direction

; Right direction pad button
rightPad1:
    LDA $4016
    AND #00000001
    CMP #1
    BNE endReadController1
    LDA #4
    STA direction

endReadController1:
