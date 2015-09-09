#include "laba1.h"

void main(int argc, char *argv[])
{
	if(argc > 1)
	{
		FILE *file = 0;
		int opt = 0, flag = 0, sh = 0, ob = 0;
		int longIndex = 0;
		char *str = 0;
		str = (char *)calloc(N, sizeof(char));
		opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
		while(opt != -1) 
		{	
			flag++;
			switch(opt)
			{
			case 'h': 
				puts("--file -f	РРјСЏ РІР°С€РµРіРѕ С„Р°Р№Р»Р°");
				puts("--string -s	РЎРёРјРІРѕР»С‹ РґР»СЏ РїРѕРёСЃРєР°");
				return;
			case 'f': 
				sh++;
				if (!file)
					file = fopen(optarg, "r");
				else
				{
					puts("Р¤Р°Р№Р» СѓР¶Рµ РёСЃРїРѕР»СЊР·СѓРµС‚СЃСЏ");
					break;
				}
				if (!file)
				{
					puts("РћС€РёР±РєР° С„Р°Р№Р»Р°");
					return;
				}
				break;
			case 's': 
				ob++;
				strcpy(str, optarg);
				break;
			}
			opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
			if (flag == 2)
			{
				if (sh == 1 && ob == 1)
					opt == -1;
				else
				{
					puts("РћС‚СЃСѓСЃС‚РІСѓСЋС‚ РїР°СЂР°РјРµС‚СЂС‹ РґР»СЏ РІС‹РїРѕР»РЅРµРёСЏ РїСЂРѕРіСЂР°РјРјС‹!");
					puts("Р’РІРµРґРёС‚Рµ --help РґР»СЏ РЅР°СЃС‚РѕР№РєРё");
					free(str);
					return;
				}
			}
		}
	func_r(file, str);
	fclose(file);
	free(str);
	}
	else 
	{
		puts("РћС‚СЃСѓСЃС‚РІСѓСЋС‚ РїР°СЂР°РјРµС‚СЂС‹ РґР»СЏ РІС‹РїРѕР»РЅРµРёСЏ РїСЂРѕРіСЂР°РјРјС‹!");
		puts("Р’РІРµРґРёС‚Рµ --help РґР»СЏ РЅР°СЃС‚РѕР№РєРё");
	}
	return;
}
