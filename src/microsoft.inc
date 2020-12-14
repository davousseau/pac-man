; Filename: microsoft.inc
; Description: Microsoft's logo shifting file
; Author: David Brousseau

    JSR setMicrosoftTowardTo
    JMP endMicrosoftShifting

; Set Linux's logo direction toward to
setMicrosoftTowardTo:
; Microsoft toward up
    LDA microsoftDirection
    CMP #1
    BNE microsoftTowardDown
    JSR shiftMicrosoftUp
    JMP endMicrosoftTowardTo

microsoftTowardDown:
    LDA microsoftDirection
    CMP #2
    BNE microsoftTowardLeft
    JSR shiftMicrosoftDown
    JMP endMicrosoftTowardTo

microsoftTowardLeft:
    LDA microsoftDirection
    CMP #3
    BNE microsoftTowardRight
    JSR shiftMicrosoftLeft
    JMP endMicrosoftTowardTo

microsoftTowardRight:
    LDA microsoftDirection
    CMP #4
    BNE endMicrosoftTowardTo
    JSR shiftMicrosoftRight

endMicrosoftTowardTo:
    RTS

; Apply shifting toward up to Microsoft's logo
shiftMicrosoftUp:
    LDA $210
    SEC
    SBC #1
    STA $210
    LDA $214
    SEC
    SBC #1
    STA $214
    LDA $218
    SEC
    SBC #1
    STA $218
    LDA $21C
    SEC
    SBC #1
    STA $21C
    RTS

; Apply shifting toward down to Linux's logo
shiftMicrosoftDown:
    LDA $210
    CLC
    ADC #1
    STA $210
    LDA $214
    CLC
    ADC #1
    STA $214
    LDA $218
    CLC
    ADC #1
    STA $218
    LDA $21C
    CLC
    ADC #1
    STA $21C
    RTS

; Apply shifting toward left to Linux's logo
shiftMicrosoftLeft:
    LDA $213
    SEC
    SBC #1
    STA $213
    LDA $217
    SEC
    SBC #1
    STA $217
    LDA $21B
    SEC
    SBC #1
    STA $21B
    LDA $21F
    SEC
    SBC #1
    STA $21F
    RTS

; Apply shifting toward right to Linux's logo
shiftMicrosoftRight:
    LDA $213
    CLC
    ADC #1
    STA $213
    LDA $217
    CLC
    ADC #1
    STA $217
    LDA $21B
    CLC
    ADC #1
    STA $21B
    LDA $21F
    CLC
    ADC #1
    STA $21F
    RTS

endMicrosoftShifting:
