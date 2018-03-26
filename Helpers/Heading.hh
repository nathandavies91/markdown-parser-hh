<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class Heading extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = true;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = true;

	/**
	 * @var string Parser regex
	 * Example 1: #{content}  =>  <h1>{content}</h1>
	 * Example 2: ##{content}  =>  <h2>{content}</h2>
	 * Example 3: ###{content}  =>  <h3>{content}</h3>
	 * Example 4: ####{content}  =>  <h4>{content}</h4>
	 * Example 5: #####{content}  =>  <h5>{content}</h5>
	 * Example 6: ######{content}  =>  <h6>{content}</h6>
	 */
	public static string $regex = "/^(?<hash>#{1,6})(?<content>.*)/";

	/**
	 * Markup for the heading element
	 * @param array<string> $content Regex values: content, hash
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup($content["content"], "h".strlen($content["hash"]));
	}
}
