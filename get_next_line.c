

#include "get_next_line.h"

static void	join_the_two_strings(char *all, char const *s1, char const *s2)
{
	size_t	i;
	int		j;

	i = 0;
	if (s1 !=0)
	{
		while (s1[i])
		{
			all[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		all[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char *s1, char *s2, int one_to_free)
{
	char	*allocated;
	size_t	string_len;
	int x;
	x = 0;
	if (s1 != NULL)
		{
			x = ft_strlen(s1);
		}
	string_len = x + strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';
	if (one_to_free == 1)
		free(s1);
	return (allocated);
}

char *line_join(char *pocket, int fd)
{
	
	char *buf;
	int cc;
	char *check;
	int i;

	i = 0;
	cc = 1;
	
	while (cc != 0)
	{
        buf = (char *) calloc(1, BUFFER_SIZE+1);
       
		cc = read(fd ,buf, BUFFER_SIZE);
        //printf("\t{{%s|%d}}\n", buf, cc);
         //printf("!!!!%s|%d|%s!!!!\n", buf,i , pocket);
         //--------\/
        if (cc == 0 && i == 0)
            return (ft_strjoin("", "",0));
        
		pocket = ft_strjoin(pocket, buf, 1);
		//printf("[[+++%s+++]]\n", pocket);
		
		check = ft_strchr(pocket, '\n');//|| ft_strchr(buf, '\0') != NULL
		//printf("[[%s||%s||%s||%d]]\n", check, buf, pocket, cc);
		if (check)
		{
			free(buf);
			return (pocket);
		}
		if (cc == -1)
			{
				free(buf);
				return (NULL);
			}
        i++;
        free(buf);
	}
    //printf("##%s##\n", pocket);
	return (pocket);
}
char *souvernire(char *pocket,char *rest)
{
	char *buf;

	int i;
	int j;

	j = 0;
	i = 0;
	if (pocket == NULL)
		return (NULL);
	if(rest[1] == '\0' || pocket[0] == '\0')
		{
            return (pocket);
			// free(pocket);
			// return (ft_strjoin("","",0));
		}
	rest++;
	buf = ft_strjoin("", rest, 0);
	rest--;
	free(pocket);
	return (buf);
}
char *pocket_change(char *pocket, char *reserve)
{
	char *buf;
	int i;

	i = 0;
	buf = ft_calloc((((long) reserve)-((long) pocket))+1, 1);

	while (pocket[i-1] != '\n')
	{
		buf[i] = pocket[i];
		i++;
	}
	return (buf);
}
char *first_line(char *rest)
{
	char *buf;

	int i;
	i = 1;
	buf = (char *) calloc(strlen(rest), 1);
	while(rest[i])
	{
		*buf = rest[i];
		i++;
		buf++;
	}
	return (buf);
}
char *get_next_line(int fd)
{
	static char *pocket;
	char *new_line_check;
	char *buffer;

	if (fd <= 0 || fd == 1 || fd == 2 || fd > 65535)
		{
           // free(pocket);
            //pocket = NULL;
            return(NULL);
        }
	// if (pocket != NULL)
    // {
    //   //  printf("@@%s@@\n", pocket);
        
    //     if (pocket[0] == '\0')
    //     {
    //         pocket = NULL;
    //         free(pocket);
    //         return (ft_strjoin("", "", 1));
    //     }
    // }
    pocket  = line_join(pocket, fd);
   // printf("\t=%s=\n", pocket);
	if (pocket == NULL)
		return (NULL);
   // printf("\t\t\t((%s}\n", pocket);
	new_line_check = ft_strchr(pocket, '\n');
	if (new_line_check)
		{
            
			buffer = pocket_change(pocket, new_line_check);
            
			// buffer = ft_strjoin(buffer, "", 1);
			//printf("\t\t\t\t\t\t\t[%s]\n", buffer);
		}
	else{
		buffer = ft_strjoin(pocket, "", 1);
       // printf("\t\t\t{%s}\n", buffer);
		pocket = NULL;
		return buffer;
	}
	pocket = souvernire(pocket, new_line_check);
	
	return (buffer);
}














// static void	join_the_two_strings(char *all, char const *s1, char const *s2)
// {
// 	size_t	i;
// 	int		j;

// 	i = 0;
// 	if (s1 !=0)
// 	{
// 		while (s1[i])
// 		{
// 			all[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		all[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// }

// char	*ft_strjoin(char *s1, char *s2, int one_to_free)
// {
	
// 	char	*allocated;
// 	size_t	string_len;
// 	int x;
// 	x = 0;
// 	if (s1 != NULL)
// 		{
// 			x = ft_strlen(s1);
// 		}
// 	string_len = x + strlen(s2);
// 	allocated = (char *)malloc(string_len + 1);
// 	if (!allocated)
// 		return (NULL);
// 	join_the_two_strings(allocated, s1, s2);
// 	allocated[string_len] = '\0';
// 	if (one_to_free == 1)
// 		free(s1);
// 	return (allocated);
// }

// char *line_join(char *pocket, int fd)
// {
	
// 	char *buf;
// 	int cc;
// 	char *check;
	
	
// 	cc = 1;
// 	buf = (char *) calloc(1, BUFFER_SIZE+1);
// 	while (cc != 0)
// 	{
		
// 		cc = read(fd ,buf, BUFFER_SIZE);
// 		//printf("\t\t\t+#%s||%zu#+\n",buf, ft_strlen(buf) );
// 		pocket = ft_strjoin(pocket, buf, 1);
// 		//if (*pocket == '\0')
		
// 		//printf("\n\n$$$$[%s]$$$$\n\n", pocket);
// 		check = ft_strchr(pocket, '\n');//|| ft_strchr(buf, '\0') != NULL
// 		//printf("[[%s||%s||%s||%d]]\n", check, buf, pocket, cc);
// 		if (check)
// 		{
// 			free(buf);
// 			return (pocket);
// 		}
// 		if (cc == -1)
// 			{
// 				free(buf);
// 				return (NULL);
// 			}
		
// 	}
// 	free(buf);
	
// 	return (pocket);
// }
// char *souvernire(char *pocket,char *rest)
// {
// 	char *buf;

// 	int i;
// 	int j;

// 	j = 0;
// 	i = 0;
// 	if (pocket == NULL)
// 		return (NULL);
// 	if(rest[1] == '\0' || pocket[0] == '\0')
// 		{
// 			free(pocket);
// 			return (ft_calloc(0,0));
// 		}
// 	//printf("\t!!%s||%ld!!\n", rest, (((long) rest)-((long) pocket)));
// 	//rest++;
// 	buf = ft_strjoin("", pocket+(((long) rest)-((long) pocket))+1, 0);///////////
// 	//rest--;
// 	free(pocket);
// 	return (buf);
// }
// char *pocket_change(char *pocket, char *reserve)
// {
// 	char *buf;
// 	int i;

// 	i = 0;
// 	if (!pocket[0])
// 		return (NULL);
// 	buf = ft_calloc((((long) reserve)-((long) pocket))+1, 1);

// 	while (pocket[i-1] != '\n')
// 	{
// 		buf[i] = pocket[i];
// 		i++;
// 	}
// 	//printf("\t{{%s}}\n", buf);
// 	return (buf);
// }
// char *first_line(char *rest)
// {
// 	char *buf;

// 	int i;
// 	i = 1;
// 	buf = (char *) calloc(strlen(rest), 1);
// 	while(rest[i])
// 	{
// 		*buf = rest[i];
// 		i++;
// 		buf++;
// 	}
// 	return (buf);
// }

// char *get_next_line(int fd)
// {
// 	static char *pocket;
// 	char *new_line_check;
// 	char *buffer;
// 	if (fd < 0)
// 		return(NULL);
// 	//if (!pocket)
// 	//	pocket = ft_calloc(0,0);
//     pocket  = line_join(pocket, fd);
// 	//printf("\t\t\t\t{{%s}}\n", pocket);
// 	if (pocket[0] == '\n' && pocket[1] == '\0')
// 		{
			
// 			return (ft_strjoin("","\n", 0));
// 		}
// 	if (pocket[0] == '\0')
// 		{
// 			return (NULL);
// 		}
// 	//printf("\t\t\t[%s]\n", pocket);
// 	if (pocket == NULL)
// 		return (NULL);
// 	new_line_check = ft_strchr(pocket, '\n');
// 	if (new_line_check)
// 		{
// 			buffer = pocket_change(pocket, new_line_check);
// 			// buffer = ft_strjoin(buffer, "", 1);
// 			//printf("\t\t\t\t\t\t\t[%s]\n", buffer);
// 		}
// 	else{
// 		buffer = ft_strjoin(pocket, "", 1);
// 		pocket = NULL;
// 		return buffer;
// 	}
// 	pocket = souvernire(pocket, new_line_check);
// 	//printf("#%s#\n", pocket);
// 	return (buffer);
// }










