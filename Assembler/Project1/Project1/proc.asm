.486

PUBLIC _procedure1@8
PUBLIC _procedure2
PUBLIC procedure3
PUBLIC procedure4
PUBLIC @procedure5@8

.model flat
.data
.code

_procedure1@8 proc
    push ebp
    mov ebp, esp

    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor esi, esi

    mov ecx, [ebp + 12]
    cmp ecx, 1
    jbe skip

    dec ecx
    mov esi, [ebp + 8]
    mov ebx, [esi]

cikl2:
    mov eax, ebx
    mov ebx, [esi + 4]
    mov [esi + 4], eax
    add esi, 4
    loop cikl2

    mov esi, [ebp + 8]
    mov [esi], ebx

skip:
    mov esp, ebp
    pop ebp
    ret 8
_procedure1@8 endp


_procedure2 proc
    push ebp
    mov ebp, esp

    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor esi, esi

    mov ecx, [ebp + 12]
    cmp ecx, 1
    jbe skip
    dec ecx
    mov esi, [ebp + 8]
    mov ebx, [esi]

cikl2:
    mov eax, ebx
    mov ebx, [esi + 4]
    mov [esi + 4], eax
    add esi, 4
    loop cikl2

    mov esi, [ebp + 8]
    mov [esi], ebx

skip:
    mov esp, ebp
    pop ebp
    ret
_procedure2 endp


procedure3 proc stdcall, arr:dword, n:dword

    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor esi, esi

    mov ecx, n
    cmp ecx, 1
    jbe skip

    dec ecx
    mov esi, arr
    mov ebx, [esi]

cikl2:
    mov eax, ebx
    mov ebx, [esi + 4]
    mov [esi + 4], eax
    add esi, 4
    loop cikl2

    mov esi, arr
    mov [esi], ebx

skip:
    ret 8
procedure3 endp


procedure4 proc c, arr:dword, n:dword

    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor esi, esi

    mov ecx, n
    cmp ecx, 1
    jbe skip

    dec ecx
    mov esi, arr
    mov ebx, [esi]
cikl2:
    mov eax, ebx
    mov ebx, [esi + 4]
    mov [esi + 4], eax
    add esi, 4
    loop cikl2

    mov esi, arr
    mov [esi], ebx
skip:
    ret
procedure4 endp


@procedure5@8 proc

    xor eax, eax
    xor ebx, ebx
    xor esi, esi
    xor edi, edi

    push ecx
    mov esi, ecx
    mov ebx, [esi]
    mov edi, edx
    xor ecx, ecx
    mov ecx, edi
    cmp ecx, 1
    jbe skip
    dec ecx

    cikl2:
    mov eax, ebx
    mov ebx, [esi + 4]
    mov [esi + 4], eax
    add esi, 4
    loop cikl2

    pop ecx
    mov esi, ecx
    mov [esi], ebx
    jmp _end

    skip:
    pop ecx
    _end:
    ret
@procedure5@8 endp

end