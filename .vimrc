" Configuration file for vim
set modelines=0		" CVE-2007-2438

" Normally we use vim-extensions. If you want true vi-compatibility
" remove change the following statements
set nocompatible	" Use Vim defaults instead of 100% vi compatibility
set backspace=2		" more powerful backspacing
set number
set ruler
syntax on
set autoindent
set smartindent
filetype plugin indent on


set mouse=a
set background=dark
"syn color changes
function! s:insert_gates()
	let gatename = substitute(toupper(expand("%:t")), "\\.", "_", "g")
	execute "normal! i#ifndef " . gatename
	execute "normal! o# define " . gatename . "\n\n\n"
	execute "normal! Go#endif"
	normal! kk
endfunction
autocmd BufNewFile *.{h,hpp} call <SID>insert_gates()
autocmd BufNewFile *.{h,hpp,c,cpp} :Stdheader

hi MatchParen  ctermfg=Black ctermbg=White
hi Visual ctermbg=White ctermfg=Black
execute pathogen#infect()
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_check_on_open = 1

" Don't write backup file if vim is being called by "crontab -e"
au BufWrite /private/tmp/crontab.* set nowritebackup nobackup
" Don't write backup file if vim is being called by "chpass"
au BufWrite /private/etc/pw.* set nowritebackup nobackup
