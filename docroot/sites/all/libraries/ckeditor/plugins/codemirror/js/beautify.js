﻿(function(){function l(b,g){for(var f=0;f<g.length;f+=1)if(g[f]===b)return!0;return!1}function B(b,g){return(new N(b,g)).beautify()}function N(b,g){function M(a,c){var d=0;a&&(d=a.indentation_level,!k.just_added_newline()&&a.line_indent_level>d&&(d=a.line_indent_level));return{mode:c,parent:a,last_text:a?a.last_text:"",last_word:a?a.last_word:"",declaration_statement:!1,declaration_assignment:!1,multiline_frame:!1,if_block:!1,else_block:!1,do_block:!1,do_while:!1,in_case_statement:!1,in_case:!1,case_body:!1,
indentation_level:d,line_indent_level:a?a.line_indent_level:d,start_line_index:k.get_line_number(),ternary_depth:0}}function n(c){var d=c.newlines;if(h.keep_array_indentation&&a.mode===f.ArrayLiteral)for(b=0;b<d;b+=1)p(0<b);else if(h.max_preserve_newlines&&d>h.max_preserve_newlines&&(d=h.max_preserve_newlines),h.preserve_newlines&&1<c.newlines){p();for(var b=1;b<d;b+=1)p(!0)}e=c;w[e.type]()}function x(a){a=void 0===a?!1:a;k.just_added_newline()||(h.preserve_newlines&&e.wanted_newline||a?p(!1,!0):
h.wrap_line_length&&k.current_line.get_character_count()+e.text.length+(k.space_before_token?1:0)>=h.wrap_line_length&&p(!1,!0))}function p(c,e){if(!e&&";"!==a.last_text&&","!==a.last_text&&"\x3d"!==a.last_text&&"TK_OPERATOR"!==d)for(;a.mode===f.Statement&&!a.if_block&&!a.do_block;)v();k.add_new_line(c)&&(a.multiline_frame=!0)}function B(){k.just_added_newline()&&(h.keep_array_indentation&&a.mode===f.ArrayLiteral&&e.wanted_newline?(k.current_line.push(e.whitespace_before),k.space_before_token=!1):
k.set_indent(a.indentation_level)&&(a.line_indent_level=a.indentation_level))}function q(a){k.raw?k.add_raw_token(e):(h.comma_first&&"TK_COMMA"===d&&k.just_added_newline()&&","===k.previous_line.last()&&(k.previous_line.pop(),B(),k.add_token(","),k.space_before_token=!0),a=a||e.text,B(),k.add_token(a))}function C(c){a?(t.push(a),y=a):y=M(null,c);a=M(y,c)}function D(a){return l(a,[f.Expression,f.ForInitializer,f.Conditional])}function v(){0<t.length&&(y=a,a=t.pop(),y.mode===f.Statement&&k.remove_redundant_indentation(y))}
function K(){return a.parent.mode===f.ObjectLiteral&&a.mode===f.Statement&&(":"===a.last_text&&0===a.ternary_depth||"TK_RESERVED"===d&&l(a.last_text,["get","set"]))}function A(){return"TK_RESERVED"===d&&l(a.last_text,["var","let","const"])&&"TK_WORD"===e.type||"TK_RESERVED"===d&&"do"===a.last_text||"TK_RESERVED"===d&&"return"===a.last_text&&!e.wanted_newline||"TK_RESERVED"===d&&"else"===a.last_text&&("TK_RESERVED"!==e.type||"if"!==e.text)||"TK_END_EXPR"===d&&(y.mode===f.ForInitializer||y.mode===f.Conditional)||
"TK_WORD"===d&&a.mode===f.BlockStatement&&!a.in_case&&"--"!==e.text&&"++"!==e.text&&"function"!==m&&"TK_WORD"!==e.type&&"TK_RESERVED"!==e.type||a.mode===f.ObjectLiteral&&(":"===a.last_text&&0===a.ternary_depth||"TK_RESERVED"===d&&l(a.last_text,["get","set"]))?(C(f.Statement),a.indentation_level+=1,"TK_RESERVED"===d&&l(a.last_text,["var","let","const"])&&"TK_WORD"===e.type&&(a.declaration_statement=!0),K()||x("TK_RESERVED"===e.type&&l(e.text,["do","for","if","while"])),!0):!1}function G(a){return l(a,
"case return do if throw else".split(" "))}function H(a){a=z+(a||0);return 0>a||a>=E.length?null:E[a]}function F(){"TK_RESERVED"===e.type&&a.mode!==f.ObjectLiteral&&l(e.text,["set","get"])&&(e.type="TK_WORD");"TK_RESERVED"===e.type&&a.mode===f.ObjectLiteral&&":"==H(1).text&&(e.type="TK_WORD");A()||!e.wanted_newline||D(a.mode)||"TK_OPERATOR"===d&&"--"!==a.last_text&&"++"!==a.last_text||"TK_EQUALS"===d||!h.preserve_newlines&&"TK_RESERVED"===d&&l(a.last_text,["var","let","const","set","get"])||p();if(a.do_block&&
!a.do_while){if("TK_RESERVED"===e.type&&"while"===e.text){k.space_before_token=!0;q();k.space_before_token=!0;a.do_while=!0;return}p();a.do_block=!1}if(a.if_block)if(a.else_block||"TK_RESERVED"!==e.type||"else"!==e.text){for(;a.mode===f.Statement;)v();a.if_block=!1;a.else_block=!1}else a.else_block=!0;if("TK_RESERVED"===e.type&&("case"===e.text||"default"===e.text&&a.in_case_statement)){p();if(a.case_body||h.jslint_happy)0<a.indentation_level&&(!a.parent||a.indentation_level>a.parent.indentation_level)&&
--a.indentation_level,a.case_body=!1;q();a.in_case=!0;a.in_case_statement=!0}else{"TK_RESERVED"===e.type&&"function"===e.text&&(!(l(a.last_text,["}",";"])||k.just_added_newline()&&!l(a.last_text,["[","{",":","\x3d",","]))||k.just_added_blankline()||e.comments_before.length||(p(),p(!0)),"TK_RESERVED"===d||"TK_WORD"===d?"TK_RESERVED"===d&&l(a.last_text,"get set new return export async".split(" "))?k.space_before_token=!0:"TK_RESERVED"===d&&"default"===a.last_text&&"export"===m?k.space_before_token=
!0:p():"TK_OPERATOR"===d||"\x3d"===a.last_text?k.space_before_token=!0:(a.multiline_frame||!D(a.mode)&&a.mode!==f.ArrayLiteral)&&p());if("TK_COMMA"===d||"TK_START_EXPR"===d||"TK_EQUALS"===d||"TK_OPERATOR"===d)K()||x();"TK_RESERVED"===e.type&&l(e.text,["function","get","set"])?(q(),a.last_word=e.text):(r="NONE","TK_END_BLOCK"===d?"TK_RESERVED"===e.type&&l(e.text,["else","catch","finally"])?"expand"===h.brace_style||"end-expand"===h.brace_style||"none"===h.brace_style&&e.wanted_newline?r="NEWLINE":
(r="SPACE",k.space_before_token=!0):r="NEWLINE":"TK_SEMICOLON"===d&&a.mode===f.BlockStatement?r="NEWLINE":"TK_SEMICOLON"===d&&D(a.mode)?r="SPACE":"TK_STRING"===d?r="NEWLINE":"TK_RESERVED"===d||"TK_WORD"===d||"*"===a.last_text&&"function"===m?r="SPACE":"TK_START_BLOCK"===d?r="NEWLINE":"TK_END_EXPR"===d&&(k.space_before_token=!0,r="NEWLINE"),"TK_RESERVED"===e.type&&l(e.text,c.line_starters)&&")"!==a.last_text&&(r="else"===a.last_text||"export"===a.last_text?"SPACE":"NEWLINE"),"TK_RESERVED"===e.type&&
l(e.text,["else","catch","finally"])?"TK_END_BLOCK"!==d||"expand"===h.brace_style||"end-expand"===h.brace_style||"none"===h.brace_style&&e.wanted_newline?p():(k.trim(!0),"}"!==k.current_line.last()&&p(),k.space_before_token=!0):"NEWLINE"===r?"TK_RESERVED"===d&&G(a.last_text)?k.space_before_token=!0:"TK_END_EXPR"!==d?"TK_START_EXPR"===d&&"TK_RESERVED"===e.type&&l(e.text,["var","let","const"])||":"===a.last_text||("TK_RESERVED"===e.type&&"if"===e.text&&"else"===a.last_text?k.space_before_token=!0:p()):
"TK_RESERVED"===e.type&&l(e.text,c.line_starters)&&")"!==a.last_text&&p():a.multiline_frame&&a.mode===f.ArrayLiteral&&","===a.last_text&&"}"===m?p():"SPACE"===r&&(k.space_before_token=!0),q(),a.last_word=e.text,"TK_RESERVED"===e.type&&"do"===e.text&&(a.do_block=!0),"TK_RESERVED"===e.type&&"if"===e.text&&(a.if_block=!0))}}var k,E=[],z,c,e,d,m,I,a,y,t,r,w,h,J="";w={TK_START_EXPR:function(){A();var b=f.Expression;if("["===e.text){if("TK_WORD"===d||")"===a.last_text){"TK_RESERVED"===d&&l(a.last_text,
c.line_starters)&&(k.space_before_token=!0);C(b);q();a.indentation_level+=1;h.space_in_paren&&(k.space_before_token=!0);return}b=f.ArrayLiteral;a.mode!==f.ArrayLiteral||"["!==a.last_text&&(","!==a.last_text||"]"!==m&&"}"!==m)||h.keep_array_indentation||p()}else"TK_RESERVED"===d&&"for"===a.last_text?b=f.ForInitializer:"TK_RESERVED"===d&&l(a.last_text,["if","while"])&&(b=f.Conditional);";"===a.last_text||"TK_START_BLOCK"===d?p():"TK_END_EXPR"===d||"TK_START_EXPR"===d||"TK_END_BLOCK"===d||"."===a.last_text?
x(e.wanted_newline):"TK_RESERVED"===d&&"("===e.text||"TK_WORD"===d||"TK_OPERATOR"===d?"TK_RESERVED"===d&&("function"===a.last_word||"typeof"===a.last_word)||"*"===a.last_text&&"function"===m?h.space_after_anon_function&&(k.space_before_token=!0):"TK_RESERVED"===d&&(l(a.last_text,c.line_starters)||"catch"===a.last_text)&&h.space_before_conditional&&(k.space_before_token=!0):k.space_before_token=!0;"("===e.text&&"TK_RESERVED"===d&&"await"===a.last_word&&(k.space_before_token=!0);"("!==e.text||"TK_EQUALS"!==
d&&"TK_OPERATOR"!==d||K()||x();C(b);q();h.space_in_paren&&(k.space_before_token=!0);a.indentation_level+=1},TK_END_EXPR:function(){for(;a.mode===f.Statement;)v();a.multiline_frame&&x("]"===e.text&&a.mode===f.ArrayLiteral&&!h.keep_array_indentation);h.space_in_paren&&("TK_START_EXPR"!==d||h.space_in_empty_paren?k.space_before_token=!0:(k.trim(),k.space_before_token=!1));"]"===e.text&&h.keep_array_indentation?(q(),v()):(v(),q());k.remove_redundant_indentation(y);a.do_while&&y.mode===f.Conditional&&
(y.mode=f.Expression,a.do_block=!1,a.do_while=!1)},TK_START_BLOCK:function(){var c=H(1),b=H(2);b&&(":"===b.text&&l(c.type,["TK_STRING","TK_WORD","TK_RESERVED"])||l(c.text,["get","set"])&&l(b.type,["TK_WORD","TK_RESERVED"]))?l(m,["class","interface"])?C(f.BlockStatement):C(f.ObjectLiteral):C(f.BlockStatement);c=!c.comments_before.length&&"}"===c.text&&"function"===a.last_word&&"TK_END_EXPR"===d;"expand"===h.brace_style||"none"===h.brace_style&&e.wanted_newline?"TK_OPERATOR"!==d&&(c||"TK_EQUALS"===
d||"TK_RESERVED"===d&&G(a.last_text)&&"else"!==a.last_text)?k.space_before_token=!0:p(!1,!0):"TK_OPERATOR"!==d&&"TK_START_EXPR"!==d?"TK_START_BLOCK"===d?p():k.space_before_token=!0:y.mode===f.ArrayLiteral&&","===a.last_text&&("}"===m?k.space_before_token=!0:p());q();a.indentation_level+=1},TK_END_BLOCK:function(){for(;a.mode===f.Statement;)v();var c="TK_START_BLOCK"===d;"expand"===h.brace_style?c||p():c||(a.mode===f.ArrayLiteral&&h.keep_array_indentation?(h.keep_array_indentation=!1,p(),h.keep_array_indentation=
!0):p());v();q()},TK_WORD:F,TK_RESERVED:F,TK_SEMICOLON:function(){A()&&(k.space_before_token=!1);for(;a.mode===f.Statement&&!a.if_block&&!a.do_block;)v();q()},TK_STRING:function(){A()?k.space_before_token=!0:"TK_RESERVED"===d||"TK_WORD"===d?k.space_before_token=!0:"TK_COMMA"===d||"TK_START_EXPR"===d||"TK_EQUALS"===d||"TK_OPERATOR"===d?K()||x():p();q()},TK_EQUALS:function(){A();a.declaration_statement&&(a.declaration_assignment=!0);k.space_before_token=!0;q();k.space_before_token=!0},TK_OPERATOR:function(){A();
if("TK_RESERVED"===d&&G(a.last_text))k.space_before_token=!0,q();else if("*"===e.text&&"TK_DOT"===d)q();else if(":"===e.text&&a.in_case)a.case_body=!0,a.indentation_level+=1,q(),p(),a.in_case=!1;else if("::"===e.text)q();else{"TK_OPERATOR"===d&&x();var b=!0,h=!0;l(e.text,["--","++","!","~"])||l(e.text,["-","+"])&&(l(d,["TK_START_BLOCK","TK_START_EXPR","TK_EQUALS","TK_OPERATOR"])||l(a.last_text,c.line_starters)||","===a.last_text)?(h=b=!1,!e.wanted_newline||"--"!==e.text&&"++"!==e.text||p(!1,!0),";"===
a.last_text&&D(a.mode)&&(b=!0),"TK_RESERVED"===d?b=!0:"TK_END_EXPR"===d?b=!("]"===a.last_text&&("--"===e.text||"++"===e.text)):"TK_OPERATOR"===d&&(b=l(e.text,["--","-","++","+"])&&l(a.last_text,["--","-","++","+"]),l(e.text,["+","-"])&&l(a.last_text,["--","++"])&&(h=!0)),a.mode!==f.BlockStatement&&a.mode!==f.Statement||"{"!==a.last_text&&";"!==a.last_text||p()):":"===e.text?0===a.ternary_depth?b=!1:--a.ternary_depth:"?"===e.text?a.ternary_depth+=1:"*"===e.text&&"TK_RESERVED"===d&&"function"===a.last_text&&
(h=b=!1);k.space_before_token=k.space_before_token||b;q();k.space_before_token=h}},TK_COMMA:function(){a.declaration_statement?(D(a.parent.mode)&&(a.declaration_assignment=!1),q(),a.declaration_assignment?(a.declaration_assignment=!1,p(!1,!0)):(k.space_before_token=!0,h.comma_first&&x())):(q(),a.mode===f.ObjectLiteral||a.mode===f.Statement&&a.parent.mode===f.ObjectLiteral?(a.mode===f.Statement&&v(),p()):(k.space_before_token=!0,h.comma_first&&x()))},TK_BLOCK_COMMENT:function(){if(k.raw)k.add_raw_token(e),
e.directives&&"end"===e.directives.preserve&&!h.test_output_raw&&(k.raw=!1);else if(e.directives)p(!1,!0),q(),"start"===e.directives.preserve&&(k.raw=!0),p(!1,!0);else if(u.newline.test(e.text)||e.wanted_newline){for(var a=e.text,a=a.replace(/\x0d/g,""),c=[],d=a.indexOf("\n");-1!==d;)c.push(a.substring(0,d)),a=a.substring(d+1),d=a.indexOf("\n");a.length&&c.push(a);var b,d=a=!1;b=e.whitespace_before;var g=b.length;p(!1,!0);if(1<c.length){var n;a:{n=c.slice(1);for(var m=0;m<n.length;m++)if("*"!==n[m].replace(/^\s+|\s+$/g,
"").charAt(0)){n=!1;break a}n=!0}if(n)a=!0;else{a:{n=c.slice(1);for(var m=0,I=n.length,f;m<I;m++)if((f=n[m])&&0!==f.indexOf(b)){b=!1;break a}b=!0}b&&(d=!0)}}q(c[0]);for(b=1;b<c.length;b++)p(!1,!0),a?q(" "+c[b].replace(/^\s+/g,"")):d&&c[b].length>g?q(c[b].substring(g)):k.add_token(c[b]);p(!1,!0)}else k.space_before_token=!0,q(),k.space_before_token=!0},TK_COMMENT:function(){e.wanted_newline?p(!1,!0):k.trim(!0);k.space_before_token=!0;q();p(!1,!0)},TK_DOT:function(){A();"TK_RESERVED"===d&&G(a.last_text)?
k.space_before_token=!0:x(")"===a.last_text&&h.break_chained_methods);q()},TK_UNKNOWN:function(){q();"\n"===e.text[e.text.length-1]&&p()},TK_EOF:function(){for(;a.mode===f.Statement;)v()}};g=g?g:{};h={};void 0!==g.braces_on_own_line&&(h.brace_style=g.braces_on_own_line?"expand":"collapse");h.brace_style=g.brace_style?g.brace_style:h.brace_style?h.brace_style:"collapse";"expand-strict"===h.brace_style&&(h.brace_style="expand");h.indent_size=g.indent_size?parseInt(g.indent_size,10):4;h.indent_char=
g.indent_char?g.indent_char:" ";h.eol=g.eol?g.eol:"\n";h.preserve_newlines=void 0===g.preserve_newlines?!0:g.preserve_newlines;h.break_chained_methods=void 0===g.break_chained_methods?!1:g.break_chained_methods;h.max_preserve_newlines=void 0===g.max_preserve_newlines?0:parseInt(g.max_preserve_newlines,10);h.space_in_paren=void 0===g.space_in_paren?!1:g.space_in_paren;h.space_in_empty_paren=void 0===g.space_in_empty_paren?!1:g.space_in_empty_paren;h.jslint_happy=void 0===g.jslint_happy?!1:g.jslint_happy;
h.space_after_anon_function=void 0===g.space_after_anon_function?!1:g.space_after_anon_function;h.keep_array_indentation=void 0===g.keep_array_indentation?!1:g.keep_array_indentation;h.space_before_conditional=void 0===g.space_before_conditional?!0:g.space_before_conditional;h.unescape_strings=void 0===g.unescape_strings?!1:g.unescape_strings;h.wrap_line_length=void 0===g.wrap_line_length?0:parseInt(g.wrap_line_length,10);h.e4x=void 0===g.e4x?!1:g.e4x;h.end_with_newline=void 0===g.end_with_newline?
!1:g.end_with_newline;h.comma_first=void 0===g.comma_first?!1:g.comma_first;h.test_output_raw=void 0===g.test_output_raw?!1:g.test_output_raw;h.jslint_happy&&(h.space_after_anon_function=!0);g.indent_with_tabs&&(h.indent_char="\t",h.indent_size=1);h.eol=h.eol.replace(/\\r/,"\r").replace(/\\n/,"\n");for(I="";0<h.indent_size;)I+=h.indent_char,--h.indent_size;var L=0;if(b&&b.length){for(;" "===b.charAt(L)||"\t"===b.charAt(L);)J+=b.charAt(L),L+=1;b=b.substring(L)}d="TK_START_BLOCK";m="";k=new O(I,J);
k.raw=h.test_output_raw;t=[];C(f.BlockStatement);this.beautify=function(){var e;c=new P(b,h,I);E=c.tokenize();for(z=0;e=H();){for(var g=0;g<e.comments_before.length;g++)n(e.comments_before[g]);n(e);m=a.last_text;d=e.type;a.last_text=e.text;z+=1}e=k.get_code();h.end_with_newline&&(e+="\n");"\n"!=h.eol&&(e=e.replace(/[\n]/g,h.eol));return e}}function Q(b){var g=0,f=-1,n=[],l=!0;this.set_indent=function(n){g=b.baseIndentLength+n*b.indent_length;f=n};this.get_character_count=function(){return g};this.is_empty=
function(){return l};this.last=function(){return this._empty?null:n[n.length-1]};this.push=function(b){n.push(b);g+=b.length;l=!1};this.pop=function(){var b=null;l||(b=n.pop(),g-=b.length,l=0===n.length);return b};this.remove_indent=function(){0<f&&(--f,g-=b.indent_length)};this.trim=function(){for(;" "===this.last();)n.pop(),--g;l=0===n.length};this.toString=function(){var g="";this._empty||(0<=f&&(g=b.indent_cache[f]),g+=n.join(""));return g}}function O(b,g){g=g||"";this.indent_cache=[g];this.baseIndentLength=
g.length;this.indent_length=b.length;this.raw=!1;var l=[];this.baseIndentString=g;this.indent_string=b;this.current_line=this.previous_line=null;this.space_before_token=!1;this.add_outputline=function(){this.previous_line=this.current_line;this.current_line=new Q(this);l.push(this.current_line)};this.add_outputline();this.get_line_number=function(){return l.length};this.add_new_line=function(b){return 1===this.get_line_number()&&this.just_added_newline()?!1:b||!this.just_added_newline()?(this.raw||
this.add_outputline(),!0):!1};this.get_code=function(){return l.join("\n").replace(/[\r\n\t ]+$/,"")};this.set_indent=function(b){if(1<l.length){for(;b>=this.indent_cache.length;)this.indent_cache.push(this.indent_cache[this.indent_cache.length-1]+this.indent_string);this.current_line.set_indent(b);return!0}this.current_line.set_indent(0);return!1};this.add_raw_token=function(b){for(var g=0;g<b.newlines;g++)this.add_outputline();this.current_line.push(b.whitespace_before);this.current_line.push(b.text);
this.space_before_token=!1};this.add_token=function(b){this.add_space_before_token();this.current_line.push(b)};this.add_space_before_token=function(){this.space_before_token&&!this.just_added_newline()&&this.current_line.push(" ");this.space_before_token=!1};this.remove_redundant_indentation=function(b){if(!b.multiline_frame&&b.mode!==f.ForInitializer&&b.mode!==f.Conditional){b=b.start_line_index;for(var g=l.length;b<g;)l[b].remove_indent(),b++}};this.trim=function(f){f=void 0===f?!1:f;for(this.current_line.trim(b,
g);f&&1<l.length&&this.current_line.is_empty();)l.pop(),this.current_line=l[l.length-1],this.current_line.trim();this.previous_line=1<l.length?l[l.length-2]:null};this.just_added_newline=function(){return this.current_line.is_empty()};this.just_added_blankline=function(){return this.just_added_newline()?1===l.length?!0:l[l.length-2].is_empty():!1}}function P(b,g,f){function n(){var d,m=[];F=0;k="";if(c>=e)return["","TK_EOF"];var f;f=z.length?z[z.length-1]:new J("TK_START_BLOCK","{");var a=b.charAt(c);
for(c+=1;l(a,x);){if(u.newline.test(a)){if("\n"!==a||"\r"!==b.charAt(c-2))F+=1,m=[]}else m.push(a);if(c>=e)return["","TK_EOF"];a=b.charAt(c);c+=1}m.length&&(k=m.join(""));if(p.test(a)){f=m=!0;var n=p;"0"===a&&c<e&&/[Xx]/.test(b.charAt(c))?(f=m=!1,a+=b.charAt(c),c+=1,n=B):(a="",--c);for(;c<e&&n.test(b.charAt(c));)a+=b.charAt(c),c+=1,m&&c<e&&"."===b.charAt(c)&&(a+=b.charAt(c),c+=1,m=!1),f&&c<e&&/[Ee]/.test(b.charAt(c))&&(a+=b.charAt(c),c+=1,c<e&&/[+-]/.test(b.charAt(c))&&(a+=b.charAt(c),c+=1),m=f=!1);
return[a,"TK_WORD"]}if(u.isIdentifierStart(b.charCodeAt(c-1))){if(c<e)for(;u.isIdentifierChar(b.charCodeAt(c))&&(a+=b.charAt(c),c+=1,c!==e););return"TK_DOT"===f.type||"TK_RESERVED"===f.type&&l(f.text,["set","get"])||!l(a,C)?[a,"TK_WORD"]:"in"===a?[a,"TK_OPERATOR"]:[a,"TK_RESERVED"]}if("("===a||"["===a)return[a,"TK_START_EXPR"];if(")"===a||"]"===a)return[a,"TK_END_EXPR"];if("{"===a)return[a,"TK_START_BLOCK"];if("}"===a)return[a,"TK_END_BLOCK"];if(";"===a)return[a,"TK_SEMICOLON"];if("/"===a){m="";if("*"===
b.charAt(c)){c+=1;D.lastIndex=c;a=D.exec(b);m="/*"+a[0];c+=a[0].length;a=m;if(a.match(K))for(f={},A.lastIndex=0,n=A.exec(a);n;)f[n[1]]=n[2],n=A.exec(a);else f=null;f&&"start"===f.ignore&&(G.lastIndex=c,a=G.exec(b),m+=a[0],c+=a[0].length);m=m.replace(u.lineBreak,"\n");return[m,"TK_BLOCK_COMMENT",f]}if("/"===b.charAt(c))return c+=1,v.lastIndex=c,a=v.exec(b),m="//"+a[0],c+=a[0].length,[m,"TK_COMMENT"]}if("`"===a||"'"===a||'"'===a||("/"===a||g.e4x&&"\x3c"===a&&b.slice(c-1).match(/^<([-a-zA-Z:0-9_.]+|{[^{}]*}|!\[CDATA\[[\s\S]*?\]\])(\s+[-a-zA-Z:0-9_.]+\s*=\s*('[^']*'|"[^"]*"|{.*?}))*\s*(\/?)\s*>/))&&
("TK_RESERVED"===f.type&&l(f.text,"return case throw else do typeof yield".split(" "))||"TK_END_EXPR"===f.type&&")"===f.text&&f.parent&&"TK_RESERVED"===f.parent.type&&l(f.parent.text,["if","while","for"])||l(f.type,"TK_COMMENT TK_START_EXPR TK_START_BLOCK TK_END_BLOCK TK_OPERATOR TK_EQUALS TK_EOF TK_SEMICOLON TK_COMMA".split(" ")))){var m=a,t=f=!1;d=a;if("/"===m)for(a=!1;c<e&&(f||a||b.charAt(c)!==m)&&!u.newline.test(b.charAt(c));)d+=b.charAt(c),f?f=!1:(f="\\"===b.charAt(c),"["===b.charAt(c)?a=!0:
"]"===b.charAt(c)&&(a=!1)),c+=1;else if(g.e4x&&"\x3c"===m){if(f=/<(\/?)([-a-zA-Z:0-9_.]+|{[^{}]*}|!\[CDATA\[[\s\S]*?\]\])(\s+[-a-zA-Z:0-9_.]+\s*=\s*('[^']*'|"[^"]*"|{.*?}))*\s*(\/?)\s*>/g,a=b.slice(c-1),(n=f.exec(a))&&0===n.index){m=n[2];for(d=0;n;){var t=!!n[1],r=n[2],w=!!n[n.length-1]||"![CDATA["===r.slice(0,8);r!==m||w||(t?--d:++d);if(0>=d)break;n=f.exec(a)}m=n?n.index+n[0].length:a.length;a=a.slice(0,m);c+=m-1;a=a.replace(u.lineBreak,"\n");return[a,"TK_STRING"]}}else for(;c<e&&(f||b.charAt(c)!==
m&&("`"===m||!u.newline.test(b.charAt(c))));){(f||"`"===m)&&u.newline.test(b.charAt(c))?("\r"===b.charAt(c)&&"\n"===b.charAt(c+1)&&(c+=1),d+="\n"):d+=b.charAt(c);if(f){if("x"===b.charAt(c)||"u"===b.charAt(c))t=!0;f=!1}else f="\\"===b.charAt(c);c+=1}if(t&&g.unescape_strings)a:{a=d;f=!1;n="";d=0;t="";for(r=0;f||d<a.length;)if(w=a.charAt(d),d++,f){f=!1;if("x"===w)t=a.substr(d,2),d+=2;else if("u"===w)t=a.substr(d,4),d+=4;else{n+="\\"+w;continue}if(!t.match(/^[0123456789abcdefABCDEF]+$/)){d=a;break a}r=
parseInt(t,16);if(0<=r&&32>r)n="x"===w?n+("\\x"+t):n+("\\u"+t);else if(34===r||39===r||92===r)n+="\\"+String.fromCharCode(r);else if("x"===w&&126<r&&255>=r){d=a;break a}else n+=String.fromCharCode(r)}else"\\"===w?f=!0:n+=w;d=n}if(c<e&&b.charAt(c)===m&&(d+=m,c+=1,"/"===m))for(;c<e&&u.isIdentifierStart(b.charCodeAt(c));)d+=b.charAt(c),c+=1;return[d,"TK_STRING"]}if("#"===a){if(0===z.length&&"!"===b.charAt(c)){for(d=a;c<e&&"\n"!==a;)a=b.charAt(c),d+=a,c+=1;return[d.replace(/^\s+|\s+$/g,"")+"\n","TK_UNKNOWN"]}m=
"#";if(c<e&&p.test(b.charAt(c))){do a=b.charAt(c),m+=a,c+=1;while(c<e&&"#"!==a&&"\x3d"!==a);"#"!==a&&("["===b.charAt(c)&&"]"===b.charAt(c+1)?(m+="[]",c+=2):"{"===b.charAt(c)&&"}"===b.charAt(c+1)&&(m+="{}",c+=2));return[m,"TK_WORD"]}}if("\x3c"===a&&("?"===b.charAt(c)||"%"===b.charAt(c))&&(H.lastIndex=c-1,m=H.exec(b)))return a=m[0],c+=a.length-1,a=a.replace(u.lineBreak,"\n"),[a,"TK_STRING"];if("\x3c"===a&&"\x3c!--"===b.substring(c-1,c+3)){c+=3;for(a="\x3c!--";!u.newline.test(b.charAt(c))&&c<e;)a+=b.charAt(c),
c++;E=!0;return[a,"TK_COMMENT"]}if("-"===a&&E&&"--\x3e"===b.substring(c-1,c+2))return E=!1,c+=2,["--\x3e","TK_COMMENT"];if("."===a)return[a,"TK_DOT"];if(l(a,q)){for(;c<e&&l(a+b.charAt(c),q)&&!(a+=b.charAt(c),c+=1,c>=e););return","===a?[a,"TK_COMMA"]:"\x3d"===a?[a,"TK_EQUALS"]:[a,"TK_OPERATOR"]}return[a,"TK_UNKNOWN"]}var x=["\n","\r","\t"," "],p=/[0-9]/,B=/[0123456789abcdefABCDEF]/,q="+ - * / % \x26 ++ -- \x3d +\x3d -\x3d *\x3d /\x3d %\x3d \x3d\x3d \x3d\x3d\x3d !\x3d !\x3d\x3d \x3e \x3c \x3e\x3d \x3c\x3d \x3e\x3e \x3c\x3c \x3e\x3e\x3e \x3e\x3e\x3e\x3d \x3e\x3e\x3d \x3c\x3c\x3d \x26\x26 \x26\x3d | || ! ~ , : ? ^ ^\x3d |\x3d :: \x3d\x3e \x3c%\x3d \x3c% %\x3e \x3c?\x3d \x3c? ?\x3e".split(" ");
this.line_starters="continue try throw return var let const if switch case default for while break function import export".split(" ");var C=this.line_starters.concat("do in else get set new catch finally typeof yield async await".split(" ")),D=/([\s\S]*?)((?:\*\/)|$)/g,v=/([^\n\r\u2028\u2029]*)/g,K=/\/\* beautify( \w+[:]\w+)+ \*\//g,A=/ (\w+)[:](\w+)/g,G=/([\s\S]*?)((?:\/\*\sbeautify\signore:end\s\*\/)|$)/g,H=/((<\?php|<\?=)[\s\S]*?\?>)|(<%[\s\S]*?%>)/g,F,k,E,z,c,e;this.tokenize=function(){e=b.length;
c=0;E=!1;z=[];for(var d,f,g,a=null,l=[],p=[];!f||"TK_EOF"!==f.type;){g=n();for(d=new J(g[1],g[0],F,k);"TK_COMMENT"===d.type||"TK_BLOCK_COMMENT"===d.type||"TK_UNKNOWN"===d.type;)"TK_BLOCK_COMMENT"===d.type&&(d.directives=g[2]),p.push(d),g=n(),d=new J(g[1],g[0],F,k);p.length&&(d.comments_before=p,p=[]);"TK_START_BLOCK"===d.type||"TK_START_EXPR"===d.type?(d.parent=f,l.push(a),a=d):("TK_END_BLOCK"===d.type||"TK_END_EXPR"===d.type)&&a&&("]"===d.text&&"["===a.text||")"===d.text&&"("===a.text||"}"===d.text&&
"{"===a.text)&&(d.parent=a.parent,a=l.pop());z.push(d);f=d}return z}}var u={};(function(b){var f=RegExp("[ªµºÀ-ÖØ-öø-ˁˆ-ˑˠ-ˤˬˮͰ-ʹͶͷͺ-ͽΆΈ-ΊΌΎ-ΡΣ-ϵϷ-ҁҊ-ԧԱ-Ֆՙա-ևא-תװ-ײؠ-يٮٯٱ-ۓەۥۦۮۯۺ-ۼۿܐܒ-ܯݍ-ޥޱߊ-ߪߴߵߺࠀ-ࠕࠚࠤࠨࡀ-ࡘࢠࢢ-ࢬऄ-हऽॐक़-ॡॱ-ॷॹ-ॿঅ-ঌএঐও-নপ-রলশ-হঽৎড়ঢ়য়-ৡৰৱਅ-ਊਏਐਓ-ਨਪ-ਰਲਲ਼ਵਸ਼ਸਹਖ਼-ੜਫ਼ੲ-ੴઅ-ઍએ-ઑઓ-નપ-રલળવ-હઽૐૠૡଅ-ଌଏଐଓ-ନପ-ରଲଳଵ-ହଽଡ଼ଢ଼ୟ-ୡୱஃஅ-ஊஎ-ஐஒ-கஙசஜஞடணதந-பம-ஹௐఅ-ఌఎ-ఐఒ-నప-ళవ-హఽౘౙౠౡಅ-ಌಎ-ಐಒ-ನಪ-ಳವ-ಹಽೞೠೡೱೲഅ-ഌഎ-ഐഒ-ഺഽൎൠൡൺ-ൿඅ-ඖක-නඳ-රලව-ෆก-ะาำเ-ๆກຂຄງຈຊຍດ-ທນ-ຟມ-ຣລວສຫອ-ະາຳຽເ-ໄໆໜ-ໟༀཀ-ཇཉ-ཬྈ-ྌက-ဪဿၐ-ၕၚ-ၝၡၥၦၮ-ၰၵ-ႁႎႠ-ჅჇჍა-ჺჼ-ቈቊ-ቍቐ-ቖቘቚ-ቝበ-ኈኊ-ኍነ-ኰኲ-ኵኸ-ኾዀዂ-ዅወ-ዖዘ-ጐጒ-ጕጘ-ፚᎀ-ᎏᎠ-Ᏼᐁ-ᙬᙯ-ᙿᚁ-ᚚᚠ-ᛪᛮ-ᛰᜀ-ᜌᜎ-ᜑᜠ-ᜱᝀ-ᝑᝠ-ᝬᝮ-ᝰក-ឳៗៜᠠ-ᡷᢀ-ᢨᢪᢰ-ᣵᤀ-ᤜᥐ-ᥭᥰ-ᥴᦀ-ᦫᧁ-ᧇᨀ-ᨖᨠ-ᩔᪧᬅ-ᬳᭅ-ᭋᮃ-ᮠᮮᮯᮺ-ᯥᰀ-ᰣᱍ-ᱏᱚ-ᱽᳩ-ᳬᳮ-ᳱᳵᳶᴀ-ᶿḀ-ἕἘ-Ἕἠ-ὅὈ-Ὅὐ-ὗὙὛὝὟ-ώᾀ-ᾴᾶ-ᾼιῂ-ῄῆ-ῌῐ-ΐῖ-Ίῠ-Ῥῲ-ῴῶ-ῼⁱⁿₐ-ₜℂℇℊ-ℓℕℙ-ℝℤΩℨK-ℭℯ-ℹℼ-ℿⅅ-ⅉⅎⅠ-ↈⰀ-Ⱞⰰ-ⱞⱠ-ⳤⳫ-ⳮⳲⳳⴀ-ⴥⴧⴭⴰ-ⵧⵯⶀ-ⶖⶠ-ⶦⶨ-ⶮⶰ-ⶶⶸ-ⶾⷀ-ⷆⷈ-ⷎⷐ-ⷖⷘ-ⷞⸯ々-〇〡-〩〱-〵〸-〼ぁ-ゖゝ-ゟァ-ヺー-ヿㄅ-ㄭㄱ-ㆎㆠ-ㆺㇰ-ㇿ㐀-䶵一-鿌ꀀ-ꒌꓐ-ꓽꔀ-ꘌꘐ-ꘟꘪꘫꙀ-ꙮꙿ-ꚗꚠ-ꛯꜗ-ꜟꜢ-ꞈꞋ-ꞎꞐ-ꞓꞠ-Ɦꟸ-ꠁꠃ-ꠅꠇ-ꠊꠌ-ꠢꡀ-ꡳꢂ-ꢳꣲ-ꣷꣻꤊ-ꤥꤰ-ꥆꥠ-ꥼꦄ-ꦲꧏꨀ-ꨨꩀ-ꩂꩄ-ꩋꩠ-ꩶꩺꪀ-ꪯꪱꪵꪶꪹ-ꪽꫀꫂꫛ-ꫝꫠ-ꫪꫲ-ꫴꬁ-ꬆꬉ-ꬎꬑ-ꬖꬠ-ꬦꬨ-ꬮꯀ-ꯢ가-힣ힰ-ퟆퟋ-ퟻ豈-舘並-龎ﬀ-ﬆﬓ-ﬗיִײַ-ﬨשׁ-זּטּ-לּמּנּסּףּפּצּ-ﮱﯓ-ﴽﵐ-ﶏﶒ-ﷇﷰ-ﷻﹰ-ﹴﹶ-ﻼＡ-Ｚａ-ｚｦ-ﾾￂ-ￇￊ-ￏￒ-ￗￚ-ￜ]"),
l=RegExp("[ªµºÀ-ÖØ-öø-ˁˆ-ˑˠ-ˤˬˮͰ-ʹͶͷͺ-ͽΆΈ-ΊΌΎ-ΡΣ-ϵϷ-ҁҊ-ԧԱ-Ֆՙա-ևא-תװ-ײؠ-يٮٯٱ-ۓەۥۦۮۯۺ-ۼۿܐܒ-ܯݍ-ޥޱߊ-ߪߴߵߺࠀ-ࠕࠚࠤࠨࡀ-ࡘࢠࢢ-ࢬऄ-हऽॐक़-ॡॱ-ॷॹ-ॿঅ-ঌএঐও-নপ-রলশ-হঽৎড়ঢ়য়-ৡৰৱਅ-ਊਏਐਓ-ਨਪ-ਰਲਲ਼ਵਸ਼ਸਹਖ਼-ੜਫ਼ੲ-ੴઅ-ઍએ-ઑઓ-નપ-રલળવ-હઽૐૠૡଅ-ଌଏଐଓ-ନପ-ରଲଳଵ-ହଽଡ଼ଢ଼ୟ-ୡୱஃஅ-ஊஎ-ஐஒ-கஙசஜஞடணதந-பம-ஹௐఅ-ఌఎ-ఐఒ-నప-ళవ-హఽౘౙౠౡಅ-ಌಎ-ಐಒ-ನಪ-ಳವ-ಹಽೞೠೡೱೲഅ-ഌഎ-ഐഒ-ഺഽൎൠൡൺ-ൿඅ-ඖක-නඳ-රලව-ෆก-ะาำเ-ๆກຂຄງຈຊຍດ-ທນ-ຟມ-ຣລວສຫອ-ະາຳຽເ-ໄໆໜ-ໟༀཀ-ཇཉ-ཬྈ-ྌက-ဪဿၐ-ၕၚ-ၝၡၥၦၮ-ၰၵ-ႁႎႠ-ჅჇჍა-ჺჼ-ቈቊ-ቍቐ-ቖቘቚ-ቝበ-ኈኊ-ኍነ-ኰኲ-ኵኸ-ኾዀዂ-ዅወ-ዖዘ-ጐጒ-ጕጘ-ፚᎀ-ᎏᎠ-Ᏼᐁ-ᙬᙯ-ᙿᚁ-ᚚᚠ-ᛪᛮ-ᛰᜀ-ᜌᜎ-ᜑᜠ-ᜱᝀ-ᝑᝠ-ᝬᝮ-ᝰក-ឳៗៜᠠ-ᡷᢀ-ᢨᢪᢰ-ᣵᤀ-ᤜᥐ-ᥭᥰ-ᥴᦀ-ᦫᧁ-ᧇᨀ-ᨖᨠ-ᩔᪧᬅ-ᬳᭅ-ᭋᮃ-ᮠᮮᮯᮺ-ᯥᰀ-ᰣᱍ-ᱏᱚ-ᱽᳩ-ᳬᳮ-ᳱᳵᳶᴀ-ᶿḀ-ἕἘ-Ἕἠ-ὅὈ-Ὅὐ-ὗὙὛὝὟ-ώᾀ-ᾴᾶ-ᾼιῂ-ῄῆ-ῌῐ-ΐῖ-Ίῠ-Ῥῲ-ῴῶ-ῼⁱⁿₐ-ₜℂℇℊ-ℓℕℙ-ℝℤΩℨK-ℭℯ-ℹℼ-ℿⅅ-ⅉⅎⅠ-ↈⰀ-Ⱞⰰ-ⱞⱠ-ⳤⳫ-ⳮⳲⳳⴀ-ⴥⴧⴭⴰ-ⵧⵯⶀ-ⶖⶠ-ⶦⶨ-ⶮⶰ-ⶶⶸ-ⶾⷀ-ⷆⷈ-ⷎⷐ-ⷖⷘ-ⷞⸯ々-〇〡-〩〱-〵〸-〼ぁ-ゖゝ-ゟァ-ヺー-ヿㄅ-ㄭㄱ-ㆎㆠ-ㆺㇰ-ㇿ㐀-䶵一-鿌ꀀ-ꒌꓐ-ꓽꔀ-ꘌꘐ-ꘟꘪꘫꙀ-ꙮꙿ-ꚗꚠ-ꛯꜗ-ꜟꜢ-ꞈꞋ-ꞎꞐ-ꞓꞠ-Ɦꟸ-ꠁꠃ-ꠅꠇ-ꠊꠌ-ꠢꡀ-ꡳꢂ-ꢳꣲ-ꣷꣻꤊ-ꤥꤰ-ꥆꥠ-ꥼꦄ-ꦲꧏꨀ-ꨨꩀ-ꩂꩄ-ꩋꩠ-ꩶꩺꪀ-ꪯꪱꪵꪶꪹ-ꪽꫀꫂꫛ-ꫝꫠ-ꫪꫲ-ꫴꬁ-ꬆꬉ-ꬎꬑ-ꬖꬠ-ꬦꬨ-ꬮꯀ-ꯢ가-힣ힰ-ퟆퟋ-ퟻ豈-舘並-龎ﬀ-ﬆﬓ-ﬗיִײַ-ﬨשׁ-זּטּ-לּמּנּסּףּפּצּ-ﮱﯓ-ﴽﵐ-ﶏﶒ-ﷇﷰ-ﷻﹰ-ﹴﹶ-ﻼＡ-Ｚａ-ｚｦ-ﾾￂ-ￇￊ-ￏￒ-ￗￚ-ￜ̀-ͯ҃-֑҇-ׇֽֿׁׂׅׄؐ-ؚؠ-ىٲ-ۓۧ-ۨۻ-ۼܰ-݊ࠀ-ࠔࠛ-ࠣࠥ-ࠧࠩ-࠭ࡀ-ࡗࣤ-ࣾऀ-ःऺ-़ा-ॏ॑-ॗॢ-ॣ०-९ঁ-ঃ়া-ৄেৈৗয়-ৠਁ-ਃ਼ਾ-ੂੇੈੋ-੍ੑ੦-ੱੵઁ-ઃ઼ા-ૅે-ૉો-્ૢ-ૣ૦-૯ଁ-ଃ଼ା-ୄେୈୋ-୍ୖୗୟ-ୠ୦-୯ஂா-ூெ-ைொ-்ௗ௦-௯ఁ-ఃె-ైొ-్ౕౖౢ-ౣ౦-౯ಂಃ಼ಾ-ೄೆ-ೈೊ-್ೕೖೢ-ೣ೦-೯ംഃെ-ൈൗൢ-ൣ൦-൯ංඃ්ා-ුූෘ-ෟෲෳิ-ฺเ-ๅ๐-๙ິ-ູ່-ໍ໐-໙༘༙༠-༩༹༵༷ཁ-ཇཱ-྄྆-྇ྍ-ྗྙ-ྼ࿆က-ဩ၀-၉ၧ-ၭၱ-ၴႂ-ႍႏ-ႝ፝-፟ᜎ-ᜐᜠ-ᜰᝀ-ᝐᝲᝳក-ឲ៝០-៩᠋-᠍᠐-᠙ᤠ-ᤫᤰ-᤻ᥑ-ᥭᦰ-ᧀᧈ-ᧉ᧐-᧙ᨀ-ᨕᨠ-ᩓ᩠-᩿᩼-᪉᪐-᪙ᭆ-ᭋ᭐-᭙᭫-᭳᮰-᮹᯦-᯳ᰀ-ᰢ᱀-᱉ᱛ-ᱽ᳐-᳒ᴀ-ᶾḁ-ἕ‌‍‿⁀⁔⃐-⃥⃜⃡-⃰ⶁ-ⶖⷠ-ⷿ〡-〨゙゚Ꙁ-ꙭꙴ-꙽ꚟ꛰-꛱ꟸ-ꠀ꠆ꠋꠣ-ꠧꢀ-ꢁꢴ-꣄꣐-꣙ꣳ-ꣷ꤀-꤉ꤦ-꤭ꤰ-ꥅꦀ-ꦃ꦳-꧀ꨀ-ꨧꩀ-ꩁꩌ-ꩍ꩐-꩙ꩻꫠ-ꫩꫲ-ꫳꯀ-ꯡ꯬꯭꯰-꯹ﬠ-ﬨ︀-️︠-︦︳︴﹍-﹏０-９＿]");
b.newline=/[\n\r\u2028\u2029]/;b.lineBreak=/\r\n|[\n\r\u2028\u2029]/g;b.isIdentifierStart=function(b){return 65>b?36===b:91>b?!0:97>b?95===b:123>b?!0:170<=b&&f.test(String.fromCharCode(b))};b.isIdentifierChar=function(b){return 48>b?36===b:58>b?!0:65>b?!1:91>b?!0:97>b?95===b:123>b?!0:170<=b&&l.test(String.fromCharCode(b))}})(u);var f={BlockStatement:"BlockStatement",Statement:"Statement",ObjectLiteral:"ObjectLiteral",ArrayLiteral:"ArrayLiteral",ForInitializer:"ForInitializer",Conditional:"Conditional",
Expression:"Expression"},J=function(b,f,l,n,u,p){this.type=b;this.text=f;this.comments_before=[];this.newlines=l||0;this.wanted_newline=0<l;this.whitespace_before=n||"";this.directives=this.parent=null};"function"===typeof define&&define.amd?define([],function(){return{js_beautify:B}}):"undefined"!==typeof exports?exports.js_beautify=B:"undefined"!==typeof window?window.js_beautify=B:"undefined"!==typeof global&&(global.js_beautify=B)})();