; Filename: controller2.inc
; Description: Game controller 2 file
; Author: David Brousseau

; Read controller 2 input
; A button
    LDA $4017
    AND #00000001
    CMP #1
    BNE b2
    LDA #1
    STA inUse

; B button
b2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE select2
    LDA #2
    STA inUse

; Select button
select2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE start2
    LDA #3
    STA inUse

; Start button
start2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE upperPad2
    LDA #4
    STA inUse

; Upper direction pad button
upperPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE lowerPad2
    JSR setUpperDirection

; Lower direction pad button
lowerPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE leftPad2
    JSR setLowerDirection

; Left direction pad button
leftPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE rightPad2
    JSR setLeftDirection

; Right direction pad button
rightPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE endReadController2
    JSR setRightDirection

endReadController2:
    JMP endController2

; Possible directions of logos
; Set upper direction to the selected logo
setUpperDirection:
; Microsoft upper direction
    LDA inUse
    CMP #1
    BNE linuxUpperDirection
    LDA #1
    STA microsoftDirection

linuxUpperDirection:
    LDA inUse
    CMP #2
    BNE appleUpperDirection
    LDA #1
    STA linuxDirection

appleUpperDirection:
    LDA inUse
    CMP #3
    BNE cetiUpperDirection
    LDA #1
    STA appleDirection

cetiUpperDirection:
    LDA inUse
    CMP #4
    BNE endSetUpperDirection
    LDA #1
    STA cetiDirection

endSetUpperDirection:
    RTS

; Set lower direction to the selected logo
setLowerDirection:
; Microsoft lower direction
    LDA inUse
    CMP #1
    BNE linuxLowerDirection
    LDA #2
    STA microsoftDirection

linuxLowerDirection:
    LDA inUse
    CMP #2
    BNE appleLowerDirection
    LDA #2
    STA linuxDirection

appleLowerDirection:
    LDA inUse
    CMP #3
    BNE cetiLowerDirection
    LDA #2
    STA appleDirection

cetiLowerDirection:
    LDA inUse
    CMP #4
    BNE endSetLowerDirection
    LDA #2
    STA cetiDirection

endSetLowerDirection:
    RTS

; Set left direction to the selected logo
setLeftDirection:
; Microsoft left direction
    LDA inUse
    CMP #1
    BNE linuxLeftDirection
    LDA #3
    STA microsoftDirection

linuxLeftDirection:
    LDA inUse
    CMP #2
    BNE appleLeftDirection
    LDA #3
    STA linuxDirection

appleLeftDirection:
    LDA inUse
    CMP #3
    BNE cetiLeftDirection
    LDA #3
    STA appleDirection

cetiLeftDirection:
    LDA inUse
    CMP #4
    BNE endSetLeftDirection
    LDA #3
    STA cetiDirection

endSetLeftDirection:
    RTS

; Set right direction to the selected logo
setRightDirection:
; Microsoft right direction
    LDA inUse
    CMP #1
    BNE linuxRightDirection
    LDA #4
    STA microsoftDirection

linuxRightDirection:
    LDA inUse
    CMP #2
    BNE appleRightDirection
    LDA #4
    STA linuxDirection

appleRightDirection:
    LDA inUse
    CMP #3
    BNE cetiRightDirection
    LDA #4
    STA appleDirection

cetiRightDirection:
    LDA inUse
    CMP #4
    BNE endSetRightDirection
    LDA #4
    STA cetiDirection

endSetRightDirection:
    RTS

endController2:
