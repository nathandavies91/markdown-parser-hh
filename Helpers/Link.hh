<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Link extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example 1: [{content}]({href} "{title}")   =>   <a href="{href}" title="{title}">{content}</a>
	 * Example 2: [{content}]({href})   =>   <a href="{href}">{content}</a>
	 */
	public static array<string> $regex = array(
		'/(^|[^!])\[(?<content>.*?)\]\((?<href>.*?) "(?<title>.*?)"\)/',
		'/(^|[^\^!])\[(?<content>.*?)\]\((?<href>.*?)\)/'
	);

	/**
	 * Markup for the link element
	 * @param array<string> $content Regex values: content, href, ?title
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return $content[1] . "<a href=\"" . $content["href"] . "\"" . (isset($content["title"]) ? " title=\"" . $content["title"] . "\"" : null) . ">" . $content["content"] . "</a>";
	}
}
