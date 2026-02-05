/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:46:32 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 20:51:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"
#include "tests.h"

// int	ft_main_render(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	if (ft_main_draw_2d(0))
// 		return (printf(AKA"❌ draw_2d failed\n"RES));
// 	if (ft_main_draw_silhouette(0))
// 		return (printf(AKA"❌ draw_silhouette failed\n"RES));
// 	if (ft_main_draw_sphere(0))
// 		return (printf(AKA"❌ draw_sphere failed\n"RES));
// 	if (ft_main_draw_world(0))
// 		return (printf(AKA"❌ draw_world failed\n"RES));
// 	if (ft_main_draw_world_shadows(0))
// 		return (printf(AKA"❌ draw_world failed\n"RES));
// 	if (ft_main_draw_sphere_pattern(0))
// 		return (printf(AKA"❌ draw_sphere_pattern failed\n"RES));
// 	if (ft_main_draw_sphere_uv(0))
// 		return (printf(AKA"❌ draw_sphere_checkers failed\n"RES));
// 	if (ft_main_draw_sphere_nested(0))
// 		return (printf(AKA"❌ draw_sphere_nested failed\n"RES));
// 	if (ft_main_draw_scene_nested(0))
// 		return (printf(AKA"❌ draw_scene_nested failed\n"RES));
// 	if (ft_main_draw_world_planes(0))
// 		return (printf(AKA"❌ draw_world failed\n"RES));
// 	if (ft_main_draw_infinite_cylinders(0))
// 		return (printf(AKA"❌ drar_infinite_cylinders failed\n"RES));
// 	if (ft_main_draw_truncated_cylinders(0))
// 		return (printf(AKA"❌ draw_truncated_cylinders failed\n"RES));
// 	if (ft_main_draw_capped_cylinders(0))
// 		return (printf(AKA"❌ draw_capped_cylinders failed\n"RES));
// 	if (ft_main_draw_cone(0))
// 		return (printf(AKA"❌ draw_cone failed\n"RES));
// 	if (ft_main_draw_icecream(0))
// 		return (printf(AKA"❌ draw_icecream failed\n"RES));
// 	if (ft_main_draw_scene_patterns_full(0))
// 		return (printf(AKA"❌ draw_patterns failed\n"RES));
// 	if (ft_main_draw_idea(0))
// 		return (printf(AKA"❌ draw_idea failed\n"RES));
// 	if (ft_main_draw_simple_cone(1))
// 		return (printf(AKA"❌ draw_simple_cone failed\n"RES));
// 	printf(G_B"END OF RENDER DEMOS\n"RES);
// 	return (0);
// }

int	run_render_with(void (*render_func)(t_engine *))
{
	t_engine	engine;

	init_engine(&engine);
	render_func(&engine);
	mlx_put_image_to_window(engine.mlx, engine.window,
		engine.image.img_ptr, 0, 0);
	printf(AKA"⚠️\tResizing the window causes the image to disappear \t⚠️\n");
	printf("\tPlease refrain from resizing the window\n"RES);
	setup_hooks(&engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
	return (0);
}

////////////////////////////////////////////////////////////////
////////////////////// RUN ALL TESTS ///////////////////////////
////////////////////////////////////////////////////////////////

// int	main()
// {
// 	// print_test_banner("RUNNING ALL TESTS");
// 	if (ft_main_tuples(0)) //1 to run , 0 to skip
// 		return (-1);
// 	if (ft_main_transform(0)) //1 to run , 0 to skip
// 		return (-1);
// 	if (ft_main_rays(0)) //1 to run, 0 to skip
// 		return (-1);
// 	if (ft_main_phong(0)) //1 to run, 0 to skip
// 		return (-1);
// 	if (ft_main_world(0)) //1 to run, 0 to skip
// 		return (-1);
// 	if (ft_main_view(0)) //1 to run, 0 to skip
// 		return (-1);
// 	if (ft_main_shadows(0)) //1 to run, 0 to skip
// 		return (-1);
// 	if (ft_main_plane(0))
// 		return (-1);
// 	if(ft_main_patt(0))
// 		return (-1);
// 	if (ft_main_cylinder(0))
// 		return (-1);
// 	if (ft_main_cone(0))
// 		return (-1);
// 	///////////////////////////////////////////////
// 	if (ft_main_render(1)) //1 to run, 0 to skip
// 		return (-1);
// 	printf(G_B"END OF ALL TESTS\n"RES);
// 	return (0);
// }

////////////////////////////////////////////////////////////////
///////////////////////// PARSING //////////////////////////////
////////////////////////////////////////////////////////////////

static void	init_data(t_input *data)
{
	data->shapes = 0;
	data->lines = NULL;
	data->list = NULL;
	data->bonus = BONUS;
}

static void	print_bonus(int bonus)
{
	if (bonus)
	{
		printf(G_B"\t   BONUS ACTIVATED!\n"RES);
		printf(GR"⚡️ Prepare for mega sonic rendering ⚡️\n");
	}
	else
	{
		printf(G_B"\t  Bonus inactive\n"RES);
		printf(GR"😴 Prepare for slow(er) rendering 😴\n");
	}
}

int	main(int ac, char **av)
{
	t_input		data;
	t_engine	engine;

	print_bonus(BONUS);
	init_data(&data);
	if (validate_and_load(ac, av, &data) != 1)
		return (-1);
	init_engine(&engine);
	draw_scene_parsed(&engine, &data.sc);
	mlx_put_image_to_window(engine.mlx, engine.window,
		engine.image.img_ptr, 0, 0);
	printf(AKA"⚠️\tResizing the window causes the image to disappear \t⚠️\n");
	printf("\tPlease refrain from resizing the window\n"RES);
	setup_hooks(&engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
	free_array(data.lines);
	free_tokens_list(data.list);
	return (0);
}
