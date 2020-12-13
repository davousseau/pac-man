; Filename: main.asm
; Description: Main game file
; Author: David Brousseau

; Declarations
    .inesprg 1 ; 1x16KB bank of PRG code
    .ineschr 1 ; 1x8KB CHR data bank
    .inesmap 0 ; No banks exchange
    .inesmir 1 ; Background mirror

; Main initialization
    .bank 0
    .org $C000 ; Writing starts at $C000
    .code ; Start of the game

; PPU & APU initialization
Reset:
    SEI ; Disable IRQ
    CLD ; Disable decimal mode
    LDX #%01000000
    STX $4017 ; disable APU metronome
    LDX #$FF
    TXS ; Initialize stack to 255
    INX
    STX $2000 ; Disable NMI
    STX $2001 ; Turn off display
    STX $4010 ; Disable DMC
    JSR VBlank

; Clear RAM memory
Clear: 
    LDA #$00
    STA $0000, x
    STA $0100, x
    STA $0300, x
    STA $0400, x
    STA $0500, x
    STA $0600, x
    STA $0700, x
    LDA #$FF
    STA $0200, x
    INX
    BNE Clear ; Repeat if x is not 0
    JSR VBlank ; Wait until the end of loading
    JSR PPUInit ; Initialize PPU

; Load color palettes into memory
; FIXME: LoadPalettes tag is not used
LoadPalettes:
    LDA $2002
    LDA #$3F
    STA $2006
    LDA #$00
    STA $2006
    LDY #$00

; Color palettes loading loop
LoadPalettesLoop:
    LDA Palettes, y
    STA $2007
    INY
    CPY #$20
    BNE LoadPalettesLoop ; Repeat if y is smaller than 32

; Load sprites into memory
; FIXME: LoadSprites tag is not used
LoadSprites:
    LDY #$00

; Sprites loading loop
LoadSpritesLoop:
    LDA Sprites, y
    STA $0200, y
    INY
    CPY #$76
    BNE LoadSpritesLoop ; Repeat if y is smaller than 4
    JSR PPUInit ; Initialize PPU again

; Initialize all the variables declared at the bottom of this file
    LDA #0
    STA counter
    STA mouth
    LDA #4
    STA direction
    LDA #1
    STA inUse
    LDA #1
    STA microsoftDirection
    LDA #2
    STA linuxDirection
    LDA #3
    STA appleDirection
    LDA #4
    STA cetiDirection

; Infinite game loop
Forever:
    JMP Forever ; Repeat until the next interruption

; Display code for each image in the game
NMI:
    LDA counter
    CLC
    ADC #1
    STA counter

; Include all required routines
;   TODO:
;    .include "pacman.inc"
;    .include "microsoft.inc"
;    .include "linux.inc"
;    .include "apple.inc"
;    .include "ceti.inc"
;    .include "controller1.inc"
;    .include "controller2.inc"

; End of NMI
; FIXME: End tag is not used
End:
    LDA #02
    STA $4014
    RTI

; Display code for each image in the game (continued)
PPUInit:
    LDA #$00
    STA $2003
    LDA #$02
    STA $4014
    LDA #%10001000 ; Loads control information from the PPU
    STA $2000
    LDA #%00011110 ; Loads the mask information from the PPU
    STA $2001
    RTS ; Return to the parent execution

; Disable PPU scroll
; FIXME: CancelScroll tag is not used
CancelScroll:
    LDA $2002
    LDA #$00
    STA $2000
    STA $2006
    STA $2005
    STA $2005
    STA $2006

; Wait until image is loaded
VBlank:
    BIT $2002
    BPL VBlank ; Repeat VBlanck if image is not loaded completely
    RTS ; Return to the parent execution

; Display
    .bank 1
    .org $E000 ; Writing starts at $E000

; Color palettes
Palettes:
;   Background, Color 1, Color 2, Color 3...
    .db $FE,$26,$16,$21, $FE,$05,$15,$25, $FE,$29,$16,$28, $FE,$0A,$1A,$2A ; Scene
;   Transparency, Color 1, Color 2, Color 3...
    .db $FE,$16,$29,$FE, $FE,$0D,$28,$30, $FE,$00,$10,$FE, $FE,$00,$11,$30 ; Sprite

; Sprites initial attributes and position
Sprites:
;   Position y, Index, Attributes, Position x
;   Pacman
    .db $78, $02, %10000001, $00
    .db $78, $00, %00000001, $08
    .db $80, $02, %00000001, $00
    .db $80, $00, %10000001, $08
;   Microsoft
    .db $77, $03, %00000000, $30
    .db $79, $04, %00000000, $37
    .db $7F, $05, %00000011, $2E
    .db $80, $06, %00000001, $36
;   Linux
    .db $78, $07, %00000001, $60
    .db $78, $08, %00000001, $68
    .db $80, $09, %00000001, $60
    .db $80, $09, %01000001, $68
;   Apple
    .db $38, $0A, %00000010, $90
    .db $38, $0B, %00000010, $98
    .db $40, $0C, %00000010, $90
    .db $40, $0D, %00000010, $98
;	Céti
    .db $B8, $0E, %00000011, $C0
    .db $B8, $0F, %00000011, $C8
    .db $C0, $10, %00000011, $C0
    .db $C0, $11, %00000011, $C8

; Interruptions
    .org $FFFA; Writing starts at $FFFA
    .dw NMI			; Start the NMI
    .dw Reset		; Reset at launch
    .dw 0			; If BRK occurs, do nothing

; Include all required routines
;   TODO:
;    .include "background.inc"
;    .include "sprites.inc"

; Zero Page
    .zp
    .org $0000; Writing starts at $0000

; Constants & Variables
; NMI counter
counter:
    .ds 1

; Pac-Man mouth (open = 0, close = 1)
mouth:
    .ds 1

; Pac-Man direction (up = 1; down = 2, left = 3, right = 4)
direction:
    .ds 1

; Logo in use (Microsoft = 1, Linux = 2, Apple = 3, Céti = 4)
inUse:
    .ds 1

; Microsoft initial direction (up = 1; down = 2, left = 3, right = 4)
microsoftDirection:
    .ds 1

; Linux initial direction (up = 1; down = 2, left = 3, right = 4)
linuxDirection:
    .ds 1

; Apple initial direction (up = 1; down = 2, left = 3, right = 4)
appleDirection:
    .ds 1

; Céti initial direction (up = 1; down = 2, left = 3, right = 4)
cetiDirection:
    .ds 1
